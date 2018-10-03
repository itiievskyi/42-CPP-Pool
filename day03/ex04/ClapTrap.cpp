/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 14:14:19 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/02 14:14:20 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {

	std::cout << "\033[1;33m" << "ClapTrap> " << "\033[0m "
	<< "Parent protocol activated. "
	<< "Ok, now you will see how the new superstar robot borns..." << std::endl;

	return;
}

ClapTrap::ClapTrap(ClapTrap const &src) {

	*this = src;

	return;
}

ClapTrap::~ClapTrap(void) {

	std::cout << "\033[1;33m" << "ClapTrap> " << "\033[0m "
	<< "Parent protocol activated. "
	<< "Another ClapTrap has passed off... Heh..." << std::endl;

	return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src) {

	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_maxHitPoints = src._maxHitPoints;
		this->_energyPoints = src._energyPoints;
		this->_maxEnergyPoints = src._maxEnergyPoints;
		this->_level = src._level;
		this->_meleeAttackDamage = src._meleeAttackDamage;
		this->_rangedAttackDamage = src._rangedAttackDamage;
		this->_armorDamageReduction = src._armorDamageReduction;
		this->_accumulatedDamage = src._accumulatedDamage;
		this->_color = src._color;
		this->_type = src._type;
	}

	return *this;
}

std::string ClapTrap::getName(void) {

	return this->_name;
}

unsigned int ClapTrap::getHitPoints(void) {

	return this->_hitPoints;
}

unsigned int ClapTrap::getMaxHitPoints(void) {

	return this->_maxHitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) {

	return this->_energyPoints;
}

unsigned int ClapTrap::getMaxEnergyPoints(void) {

	return this->_maxEnergyPoints;
}

unsigned int ClapTrap::getMeleeAttackDamage(void) {

	return this->_meleeAttackDamage;
}

unsigned int ClapTrap::getRangedAttackDamage(void) {

	return this->_rangedAttackDamage;
}

unsigned int ClapTrap::getArmorDamageReduction(void) {

	return this->_armorDamageReduction;
}

void	ClapTrap::checkLevel(void) {

	if (this->_accumulatedDamage / 100 >= this->_level) {
		++this->_level;
		this->_energyPoints = this->_maxEnergyPoints;
		std::cout << this->_color << this->_name << ">\033[0m " <<
		"Now I will dominate!" << " ";
		std::cout << "<" << this->_type << " " << this->_name <<
		" reaches level " << this->_level << "! ";
		std::cout << "Energy: " << this->_energyPoints << " points.>"
		<< std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name
		<< " looks dead.>" << std::endl;
		return;
	}

	unsigned int actualAmount;

	if (this->_armorDamageReduction > 0) {
		--this->_armorDamageReduction;
		if (amount > 10) {
			actualAmount = amount - 10;
		} else {
			actualAmount = 0;
		}
	} else {
		actualAmount = amount;
	}
	if (actualAmount >= this->_hitPoints) {
		std::cout << this->_color << this->_name << ">\033[0m " <<
		"Argh arghargh death gurgle gurglegurgle urgh... death." << " ";
		std::cout << "<" << this->_type << " " << this->_name << " takes "
		<< this->_hitPoints << " points of damage. HP: ";
		this->_hitPoints = 0;
		std::cout << this->_hitPoints << " points. Armor: ";
		std::cout << this->_armorDamageReduction << " points.>" << std::endl;
	} else if (actualAmount == 0) {
		std::cout << this->_color << this->_name << ">\033[0m " <<
		"HA! HAA! HAAAA! Looooooooooseeeer" << " ";
		std::cout << "<" << this->_type << " " << this->_name << " takes "
		<< actualAmount << " points of damage. HP: " << this->_hitPoints
		<< " points. Armor: ";
		std::cout << this->_armorDamageReduction << " points.>" << std::endl;
	} else {
		this->_hitPoints -= actualAmount;
		std::cout << this->_color << this->_name << ">\033[0m " <<
		"My robotic flesh! AAHH!" << " ";
		std::cout << "<" << this->_type << " " << this->_name << " takes "
		<< actualAmount << " points of damage. HP: " << this->_hitPoints
		<< " points. Armor: ";
		std::cout << this->_armorDamageReduction << " points.>" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name
		<< " looks dead.>" << std::endl;
		return;
	}

	if (this->_energyPoints == 0) {
		std::cout << this->_color << this->_name << ">\033[0m " <<
		"Ooops! Somebody here needs tasty piece of energy..." << std::endl;
		return;
	}

	unsigned int actualAmount;

	if (amount >= this->_energyPoints) {
		actualAmount = this->_energyPoints;
		this->_energyPoints = 0;
	} else {
		actualAmount = amount;
		this->_energyPoints -= amount;
	}

	std::cout << this->_color << this->_name << ">\033[0m " <<
	"Sweet life juice!" << " ";
	if (actualAmount >= this->_maxHitPoints - this->_hitPoints) {
		std::cout << "<" << this->_type << " " << this->_name << " restores "
		<< this->_maxHitPoints - this->_hitPoints << " hit points. HP: ";
		this->_hitPoints = _maxHitPoints;
		std:: cout << this->_hitPoints << " points. Energy: "
		<< this->_energyPoints << " points.>" << std::endl;
	} else {
		this->_hitPoints += actualAmount;
		std::cout << "<" << this->_type << " " << this->_name << " restores "
		<< actualAmount << " hit points. HP: "
		<< this->_hitPoints << " points Energy: "
		<< this->_energyPoints << " points.>" << std::endl;
	}
}
