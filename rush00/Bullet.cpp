/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:07:46 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/06 16:07:47 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(void) {

	return;
}

Bullet::Bullet(int x, int y) {

	this->_x = x;
	this->_y = y;
	this->_type = '-';
	this->_bad = true;
	this->_color = 5;
	this->_damage = 5;

	return;
}

Bullet::Bullet(bool owner, int x, int y) {

	this->_x = x;
	this->_y = y;
	this->_type = '-';
	this->_bad = owner;
	this->_color = 4;
	this->_damage = 5;

	return;
}

Bullet::Bullet(char type, int x, int y) {

	this->_x = x;
	this->_y = y;
	this->_type = type;
	this->_bad = true;
	this->_color = 5;
	this->_damage = 10;

	return;
}

Bullet::Bullet(Bullet const &e) {

	*this = e;

	return;
}

Bullet::~Bullet() {

	return;
}

Bullet & Bullet::operator=(Bullet const &e) {
	if (this != &e) {
		this->_x = e.getX();
		this->_y = e.getY();
		this->_type = e.getType();
		this->_bad = e.getBad();
		this->_color = e.getColor();
		this->_damage = e.getDamage();
	}
	return *this;
}

int  Bullet::getX() const {

	return this->_x;
}

int  Bullet::getY() const {

	return this->_y;
}

char  Bullet::getType() const {

	return this->_type;
}
bool  Bullet::getBad() const {

	return this->_bad;
}
int  Bullet::getColor() const {

	return this->_color;
}
int  Bullet::getDamage() const {

	return this->_damage;
}

void Bullet::setX(int x) {

	this->_x = x;
}

void Bullet::setY(int y) {

	this->_y = y;
}

void Bullet::setType(char type) {

	this->_type = type;
}
void Bullet::setBad(bool owner) {

	this->_bad = owner;
}
void Bullet::setColor(int color) {

	this->_color = color;
}
void Bullet::setDamage(int damage) {

	this->_damage = damage;
}
