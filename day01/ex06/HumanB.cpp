/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:52:57 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/26 10:52:58 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) {

	this->_name = name;

	return;
}

HumanB::~HumanB(void) {

	return;
}

void	HumanB::attack(void) const {

	std::cout << this->_name << " attacks with his " << this->_weapon->getType()
	<< std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {

	this->_weapon = &weapon;
}
