/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:24:09 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/02 17:24:11 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : FragTrap(1), NinjaTrap(1) {

	this->_name = name;
	this->_level = 1;

	this->_accumulatedDamage = 0;

	this->_color = "\033[1;36m";
	this->_type = "SPR-TP";

	std::cout << this->_color << this->_name << ">\033[0m " << "Hi! I'm "
	<< this->_name << "! Meet the SUPERSTAR!!!" << std::endl;

	return;
}

SuperTrap::SuperTrap(SuperTrap const &src) {

	*this = src;

	return;
}

SuperTrap::SuperTrap(void) {

	static int count = 0;

	this->_name = "Super" + std::to_string(count);
	this->_level = 1;

	this->_accumulatedDamage = 0;

	this->_color = "\033[1;36m";
	this->_type = "SPR-TP";

	std::cout << this->_color << this->_name << ">\033[0m " << "Hi! I'm "
	<< this->_name << "! Meet the SUPERSTAR!!!" << std::endl;

	++count;

	return;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &src) {

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

SuperTrap::~SuperTrap(void) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name <<
		"Hm... This robot is too heavy to clean after it.>" << std::endl;
	} else {
		std::cout << this->_color << this->_name << ">\033[0m " <<
		"I'm immortal! HA-HA-H..." << " ";
		std::cout << "<" << this->_type << " " << this->_name << " turned off.>"
		<< std::endl;
	}

	return;
}

void	SuperTrap::rangedAttack(std::string const &target) {

	return (FragTrap::rangedAttack(target));
}

void	SuperTrap::meleeAttack(std::string const &target) {

	return (NinjaTrap::meleeAttack(target));
}
