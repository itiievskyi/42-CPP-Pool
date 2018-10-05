/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:37:29 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:37:31 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) {

	this->_name = name;
	this->_apcost = apcost;
	this->_damage = damage;

	return;
}

AWeapon::AWeapon(AWeapon const &src) {

	*this = src;

	return;
}

AWeapon &AWeapon::operator=(AWeapon const &src) {

	if (this != &src) {
		this->_name = src.getName();
		this->_apcost = src.getAPCost();
		this->_damage = src.getDamage();
	}

	return *this;
}

AWeapon::~AWeapon(void) {

	return;
}

std::string AWeapon::getName(void) const
{
	return this->_name;
}

int AWeapon::getDamage(void) const
{
	return this->_damage;
}

int AWeapon::getAPCost(void) const
{
	return this->_apcost;
}
