/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:40:12 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:40:13 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string		letter1 = "aoeiu";
std::string		letter2 = "wrtpsdfghklbnmc";

Character::Character(void) {

	std::srand(std::time(nullptr));

	static int count = 0;

	int length = ((int)std::rand() + count * 5) % 8 + 2;
	std::string name = "         ";

	name.resize(length);

	for (int i = 0; i < length; i++) {
		if (i == 0) {
			name[i] =
			std::toupper(letter2[(std::rand() + count) % letter2.length()]);
		} else if (i % 2 == 0) {
			name[i] = letter2[(std::rand() + count) % letter2.length()];
		} else {
			name[i] = letter1[(std::rand() + count) % letter1.length()];
		}
	}
	name[length] = '\0';

	this->_name = name;
	this->_ap = 40;
	this->_maxAp = 40;
	this->_equipped = false;

	count += 1;

	return;
}

Character::Character(std::string const &name) {

	this->_name = name;
	this->_ap = 40;
	this->_maxAp = 40;
	this->_equipped = false;

	return;
}

Character::Character(Character const &src) {

	*this = src;

	return;
}

Character &Character::operator=(Character const &src) {

	if (this != &src) {
		this->_ap = src.getAP();
		this->_maxAp = src.getMaxAP();
		this->_name = src.getName();
		this->_equipped = src.getEquipped();
		this->_weapon = src.getWeapon();
	}

	return *this;
}

Character::~Character(void) {

	return;
}

void Character::recoverAP(void) {

	if (this->_ap >= this->_maxAp - 10) {
		this->_ap = 40;
	} else {
		this->_ap += 10;
	}

	return;
}

void Character::equip(AWeapon *wpn) {

	this->_weapon = wpn;
	this->_equipped = true;

	return;
}

void Character::attack(Enemy *frag) {

	if (this->_equipped == false || this->_weapon->getAPCost() > this->_ap) {
		std::cout << "* nothing happened *" << std::endl;
		return;
	} else {
		this->_ap -= this->_weapon->getAPCost();
	}

	std::cout << this->getName() << " attacks " << frag->getType() <<
	" with a " << this->_weapon->getName() << std::endl;

	this->_weapon->attack();

	frag->takeDamage(this->_weapon->getDamage());
	if (frag->getHP() == 0) {
		frag->~Enemy();
	}

	return;
}

std::string Character::getName(void) const {

	return this->_name;
}

int Character::getAP(void) const {

	return this->_ap;
}

int Character::getMaxAP(void) const {

	return this->_maxAp;
}

AWeapon *Character::getWeapon(void) const {

	return this->_weapon;
}

bool Character::getEquipped(void) const {

	return this->_equipped;
}

std::ostream &operator<<(std::ostream &o, Character const &src) {

	std::cout << src.getName() <<  " has " << src.getAP() << " AP and ";
	if (!src.getEquipped()) {
		std::cout << "is unarmed";
	} else {
		std::cout << "wields a " << src.getWeapon()->getName();
	}
	std::cout << std::endl;
	return o;
}
