/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 12:49:25 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/02 12:49:26 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) {

	this->_name = name;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;

	this->_accumulatedDamage = 0;

	this->_color = "\033[1;32m";
	this->_type = "SC4V-TP";

	std::cout << this->_color << this->_name << ">\033[0m " << this->_name <<
	" in da house! Look out everybody! Things are about to get awesome!"
	<< std::endl;

	return;
}

ScavTrap::ScavTrap(ScavTrap const &src) {

	*this = src;

	return;
}

ScavTrap::ScavTrap(void) {

	static int count = 0;

	this->_name = "Scav" + std::to_string(count);
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;

	this->_accumulatedDamage = 0;

	this->_color = "\033[1;32m";
	this->_type = "SC4V-TP";

	std::cout << this->_color << this->_name << ">\033[0m " << this->_name <<
	" in da house! Look out everybody! Things are about to get awesome!"
	<< std::endl;

	++count;

	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src) {

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

ScavTrap::~ScavTrap(void) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name <<
		"'s body is going to be recycled>" << std::endl;
	} else {
		std::cout << this->_color << this->_name << ">\033[0m " <<
		"You can't just turn me off, can you? No, I'm serious. You c.." << " ";
		std::cout << "<" << this->_type << " " << this->_name << " turned off.>"
		<< std::endl;
	}

	return;
}

void	ScavTrap::rangedAttack(std::string const &target) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name
		<< " looks dead.>" << std::endl;
		return;
	}
	std::cout << this->_color << this->_name << ">\033[0m " <<
	"Present for you!" << " ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " throws a grenade to " << target << ", causing "
	<< this->_rangedAttackDamage << " points of damage!>" << std::endl;

	this->_accumulatedDamage += this->_rangedAttackDamage;
	this->checkLevel();
}

void	ScavTrap::meleeAttack(std::string const &target) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name << " looks dead.>"
		<< std::endl;
		return;
	}
	std::cout << this->_color << this->_name << ">\033[0m " <<
	"Take that, you piece of <censored>!" << " ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " performs melee attack against " << target << ", causing "
	<< this->_meleeAttackDamage << " points of damage!>" << std::endl;

	this->_accumulatedDamage += this->_meleeAttackDamage;
	this->checkLevel();
}

void	ScavTrap::challengeNewcomer(std::string const &target) {

	std::srand(std::time(nullptr));

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name << " looks dead.>"
		<< std::endl;
		return;
	}

	static int count = 0;

	int chNum = ((int)std::rand() + count * 5) % 4;

	std::string challenges[5] = {
		"bring me your own corpse. Pleeeease...",
		"take me some nuclear bombs, hm?",
		"just run away as fast as you can, fresh meat!",
		"kiss my shiny metal ass!",
		"bring me some flavor machine oil. I think I can use yours..."
	};
	std::cout << this->_color << this->_name << ">\033[0m ";
	std::cout << "Hey, you! Yes, you, " << target << "! Not so quick... ";
	std::cout << "If you want to live, " << challenges[chNum] << std::endl;

	++count;

}
