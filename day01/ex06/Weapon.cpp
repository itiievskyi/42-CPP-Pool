/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:53:11 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/26 10:53:12 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) {

	this->_type = type;
	return;
}

Weapon::~Weapon(void) {

	return;
}

const std::string &Weapon::getType(void) const {

	return this->_type;
}

void		Weapon::setType(std::string type) {

	this->_type = type;
}
