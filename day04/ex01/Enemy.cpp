/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:38:41 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:38:42 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) {

	this->_hp = 50;
	this->_type = "Weird being";

	return;
}

Enemy::Enemy(int hp, std::string const &type) {

	this->_hp = hp;
	this->_type = type;

	return;
}

Enemy::Enemy(Enemy const &src) {

	*this = src;

	return;
}

Enemy &Enemy::operator=(Enemy const &src) {

	if (this != &src) {
		this->_hp = src.getHP();
		this->_type = src.getType();
	}

	return *this;
}

Enemy::~Enemy(void) {

	return;
}

int Enemy::getHP(void) const {

	return (this->_hp);
}

void Enemy::setHP(int hp) {

	if (hp >= 0) {
		this->_hp = hp;
	}
}

std::string Enemy::getType(void) const {

	return (this->_type);
}

void Enemy::takeDamage(int damage) {

	if (this->_hp > 0 && damage > 0) {
		if (damage >= this->_hp) {
			this->_hp = 0;
		} else {
			this->_hp -= damage;
		}
	}

	return;
}
