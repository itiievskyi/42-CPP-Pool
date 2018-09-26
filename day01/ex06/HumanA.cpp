/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:52:38 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/26 10:52:39 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) {

	this->_name = name;
	this->_weapon = &weapon;

	return;
}

HumanA::~HumanA(void) {

	return;
}

void	HumanA::attack(void) const {

	std::cout << this->_name << " attacks with his " << this->_weapon->getType()
	<< std::endl;
}
