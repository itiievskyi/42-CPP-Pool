/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:01:25 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/02 16:01:26 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) {

	this->_name = name;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;

	this->_accumulatedDamage = 0;

	this->_color = "\033[1;35m";
	this->_type = "NNJ-TP";

	std::cout << this->_color << this->_name << ">\033[0m " << "Hi! I'm "
	<< this->_name << "! Let's get this party started!" << std::endl;

	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) {

	*this = src;

	return;
}

NinjaTrap::NinjaTrap(void) {

	static int count = 0;

	this->_name = "Ninja" + std::to_string(count);
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;

	this->_accumulatedDamage = 0;

	this->_color = "\033[1;35m";
	this->_type = "NNJ-TP";

	std::cout << this->_color << this->_name << ">\033[0m " << "Hi! I'm "
	<< this->_name << "! Let's get this party started!" << std::endl;

	++count;

	return;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &src) {

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

NinjaTrap::~NinjaTrap(void) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name <<
		"'s body is just disappeared...>" << std::endl;
	} else {
		std::cout << this->_color << this->_name << ">\033[0m " <<
		"You will regret abou..." << " ";
		std::cout << "<" << this->_type << " " << this->_name << " turned off.>"
		<< std::endl;
	}

	return;
}

void	NinjaTrap::rangedAttack(std::string const &target) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name
		<< " looks dead.>" << std::endl;
		return;
	}
	std::cout << this->_color << this->_name << ">\033[0m " <<
	"I'm silent like a wind. You even won't recognize me (he-he)" << " ";
	std::cout << "<" << this->_type << " " << this->_name << " attacks "
	<< target << " with a shuriken, causing " << this->_rangedAttackDamage <<
	" points of damage!>" << std::endl;

	this->_accumulatedDamage += this->_rangedAttackDamage;
	this->checkLevel();
}

void	NinjaTrap::meleeAttack(std::string const &target) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name
		<< " looks dead.>" << std::endl;
		return;
	}
	std::cout << this->_color << this->_name << ">\033[0m " <<
	"For Robo-yakuza!!!" << " ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " uses nunchuck against " << target << ", causing "
	<< this->_meleeAttackDamage << " points of damage!>" << std::endl;

	this->_accumulatedDamage += this->_meleeAttackDamage;
	this->checkLevel();
}

void 	NinjaTrap::ninjaShoebox(NinjaTrap &target) {

	if (target._name == this->_name) {
		std::cout << this->_color << this->_name << ">\033[0m ";
		std::cout << "Hey, me, wanna some sushi? Of course, I want! ";
	} else {
		std::cout << this->_color << this->_name << ">\033[0m ";
		std::cout << "Hey, bro, wanna some sushi? Of course, you want! ";
	}
	std::cout << "<" << this->_type << " " << this->_name
	<< " brings awesome sushi set.>" << std::endl;
}

void 	NinjaTrap::ninjaShoebox(ClapTrap &target) {

	std::cout << this->_color << this->_name << ">\033[0m ";
	std::cout << "Aaaa... what are you? Clap... or Frag... or... whatever... ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " looks confused! He let ClapTrap " << target.getName()
	<< " go. For now.>" << std::endl;
}

void 	NinjaTrap::ninjaShoebox(FragTrap &target) {

	std::cout << this->_color << this->_name << ">\033[0m ";
	std::cout << "Son of a Frag! Now I'll kill you!!! ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " performs his most powerful nunchuck attack against "
	<< target.getName() << ", causing 70 points of damage!>" << std::endl;
	target.takeDamage(70);
}

void 	NinjaTrap::ninjaShoebox(ScavTrap &target) {

	std::cout << this->_color << this->_name << ">\033[0m ";
	std::cout << "Ohh... another one Scav. Eat my shuriken! ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " throws 5 shurikens to " << target.getName() <<
	", causing 25 points of damage!>" << std::endl;
	target.takeDamage(25);
}
