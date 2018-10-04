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

	std::cout << "\033[1;32m" << this->_name << ">\033[0m " << this->_name <<
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

	std::cout << "\033[1;32m" << this->_name << ">\033[0m " << this->_name <<
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

	}

	return *this;
}

ScavTrap::~ScavTrap(void) {

	if (this->_hitPoints == 0) {
		std::cout << "<SC4V-TP " << this->_name <<
		"'s body is going to be recycled>" << std::endl;
	} else {
		std::cout << "\033[1;32m" << this->_name << ">\033[0m " <<
		"You can't just turn me off, can you? No, I'm serious. You c.." << " ";
		std::cout << "<SC4V-TP " << this->_name << " turned off.>" << std::endl;
	}

	return;
}

std::string ScavTrap::getName(void) {

	return this->_name;
}

unsigned int ScavTrap::getMeleeAttackDamage(void) {

	return this->_meleeAttackDamage;
}

unsigned int ScavTrap::getRangedAttackDamage(void) {

	return this->_rangedAttackDamage;
}

void	ScavTrap::checkLevel(void) {

	if (this->_accumulatedDamage / 100 >= this->_level) {
		++this->_level;
		this->_energyPoints = this->_maxEnergyPoints;
		std::cout << "\033[1;32m" << this->_name << ">\033[0m " <<
		"Check me out!" << " ";
		std::cout << "<SC4V-TP " << this->_name << " reaches level " <<
		this->_level << "! ";
		std::cout << "Energy: " << this->_energyPoints << " points.>"
		<< std::endl;
	}
}

void	ScavTrap::rangedAttack(std::string const &target) {

	if (this->_hitPoints == 0) {
		std::cout << "<SC4V-TP " << this->_name << " looks dead.>" << std::endl;
		return;
	}
	std::cout << "\033[1;32m" << this->_name << ">\033[0m " <<
	"Present for you!" << " ";
	std::cout << "<SC4V-TP " << this->_name << " throws a grenade to " << target
	<< ", causing " << this->_rangedAttackDamage <<
	" points of damage!>" << std::endl;

	this->_accumulatedDamage += this->_rangedAttackDamage;
	this->checkLevel();
}

void	ScavTrap::meleeAttack(std::string const &target) {

	if (this->_hitPoints == 0) {
		std::cout << "<SC4V-TP " << this->_name << " looks dead.>" << std::endl;
		return;
	}
	std::cout << "\033[1;32m" << this->_name << ">\033[0m " <<
	"Take that, you piece of <censored>!" << " ";
	std::cout << "<SC4V-TP " << this->_name << " performs melee attack against "
	<< target << ", causing " << this->_meleeAttackDamage <<
	" points of damage!>" << std::endl;

	this->_accumulatedDamage += this->_meleeAttackDamage;
	this->checkLevel();
}

void	ScavTrap::takeDamage(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << "<SC4V-TP " << this->_name << " looks dead.>" << std::endl;
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
		std::cout << "\033[1;32m" << this->_name << ">\033[0m " <<
		"No fair! I wasn't ready." << " ";
		std::cout << "<SC4V-TP " << this->_name << " takes "
		<< this->_hitPoints << " points of damage. HP: ";
		this->_hitPoints = 0;
		std::cout << this->_hitPoints << " points. Armor: ";
		std::cout << this->_armorDamageReduction << " points.>" << std::endl;
	} else if (actualAmount == 0) {
		std::cout << "\033[1;32m" << this->_name << ">\033[0m " <<
		"Looooooooooseeeer" << " ";
		std::cout << "<SC4V-TP " << this->_name << " takes "
		<< actualAmount << " points of damage. HP: " << this->_hitPoints
		<< " points. Armor: ";
		std::cout << this->_armorDamageReduction << " points.>" << std::endl;
	} else {
		this->_hitPoints -= actualAmount;
		std::cout << "\033[1;32m" << this->_name << ">\033[0m " <<
		"My robotic flesh! AAHH!" << " ";
		std::cout << "<SC4V-TP " << this->_name << " takes "
		<< actualAmount << " points of damage. HP: " << this->_hitPoints
		<< " points. Armor: ";
		std::cout << this->_armorDamageReduction << " points.>" << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << "<SC4V-TP " << this->_name << " looks dead.>" << std::endl;
		return;
	}

	if (this->_energyPoints == 0) {
		std::cout << "\033[1;32m" << this->_name << ">\033[0m " <<
		"Give me a power socket. Now!" << std::endl;
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

	std::cout << "\033[1;32m" << this->_name << ">\033[0m " <<
	"Health over here! Please wait for me!" << " ";
	if (actualAmount >= this->_maxHitPoints - this->_hitPoints) {
		std::cout << "<SC4V-TP " << this->_name << " restores "
		<< this->_maxHitPoints - this->_hitPoints << " hit points. HP: ";
		this->_hitPoints = _maxHitPoints;
		std:: cout << this->_hitPoints << " points. Energy: "
		<< this->_energyPoints << " points.>" << std::endl;
	} else {
		this->_hitPoints += actualAmount;
		std::cout << "<SC4V-TP " << this->_name << " restores "
		<< actualAmount << " hit points. HP: "
		<< this->_hitPoints << " points Energy: "
		<< this->_energyPoints << " points.>" << std::endl;
	}
}

void	ScavTrap::challengeNewcomer(std::string const &target) {

	std::srand(std::time(nullptr));

	if (this->_hitPoints == 0) {
		std::cout << "<SC4V-TP " << this->_name << " looks dead.>" << std::endl;
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
	std::cout << "\033[1;32m" << this->_name << ">\033[0m ";
	std::cout << "Hey, you! Yes, you, " << target << "! Not so quick... ";
	std::cout << "If you want to live, " << challenges[chNum] << std::endl;

	++count;

}
