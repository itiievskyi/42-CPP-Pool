/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 08:52:01 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/02 08:52:05 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name) {

	this->_name = name;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;

	this->_funzerkerDamage = 40;
	this->_blightbotDamage = 40;
	this->_miniontrapDamage = 40;
	this->_clapInTheBoxDamage = 40;
	this->_laserInfernoDamage = 40;

	this->_accumulatedDamage = 0;

	this->_color = "\033[1;31m";
	this->_type = "FR4G-TP";

	std::cout << this->_color << this->_name << ">\033[0m " << "Hi! I'm "
	<< this->_name << "! Let's get this party started!" << std::endl;

	return;
}

FragTrap::FragTrap(FragTrap const &src) {

	*this = src;

	return;
}

FragTrap::FragTrap(void) {

	return;
}

FragTrap &FragTrap::operator=(FragTrap const &src) {

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
		this->_funzerkerDamage = src._funzerkerDamage;
		this->_blightbotDamage = src._blightbotDamage;
		this->_miniontrapDamage = src._miniontrapDamage;
		this->_clapInTheBoxDamage = src._clapInTheBoxDamage;
		this->_laserInfernoDamage = src._laserInfernoDamage;
	}

	return *this;
}

FragTrap::~FragTrap(void) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name <<
		"'s body is going to be recycled>" << std::endl;
	} else {
		std::cout << this->_color << this->_name << ">\033[0m " <<
		"Hey, what the f... ------ " << " ";
		std::cout << "<" << this->_type << " " << this->_name << " turned off.>"
		<< std::endl;
	}

	return;
}

unsigned int FragTrap::getFunzerkerDamage(void) {

	return this->_funzerkerDamage;
}

unsigned int FragTrap::getBlightbotDamage(void) {

	return this->_blightbotDamage;
}

unsigned int FragTrap::getMiniontrapDamage(void) {

	return this->_miniontrapDamage;
}

unsigned int FragTrap::getClapInTheBoxDamage(void) {

	return this->_clapInTheBoxDamage;
}

unsigned int FragTrap::getLaserInfernoDamage(void) {

	return this->_laserInfernoDamage;
}

void	FragTrap::rangedAttack(std::string const &target) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name
		<< " looks dead.>" << std::endl;
		return;
	}
	std::cout << this->_color << this->_name << ">\033[0m " <<
	"That looks like it hurts!" << " ";
	std::cout << "<" << this->_type << " " << this->_name << " attacks "
	<< target << " at range, causing " << this->_rangedAttackDamage <<
	" points of damage!>" << std::endl;

	this->_accumulatedDamage += this->_rangedAttackDamage;
	this->checkLevel();
}

void	FragTrap::meleeAttack(std::string const &target) {

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name
		<< " looks dead.>" << std::endl;
		return;
	}
	std::cout << this->_color << this->_name << ">\033[0m " <<
	"Heyyaaaaaah!" << " ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " performs melee attack against " << target << ", causing "
	<< this->_meleeAttackDamage << " points of damage!>" << std::endl;

	this->_accumulatedDamage += this->_meleeAttackDamage;
	this->checkLevel();
}

void	FragTrap::funzerker(std::string const &target) {

	std::cout << this->_color << this->_name << ">\033[0m " <<
	"Don't ask me where this ammo's coming from!" << " ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " use funzerker against " << target << ", causing "
	<< this->_funzerkerDamage << " points of damage! Energy: ";

}

void	FragTrap::miniontrap(std::string const &target) {

	std::cout << this->_color << this->_name << ">\033[0m " <<
	"Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!"
	<< " ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " sets the minion trap against " << target << ", causing "
	<< this->_miniontrapDamage << " points of damage! Energy: ";

}

void	FragTrap::blightbot(std::string const &target) {

	std::cout << this->_color << this->_name << ">\033[0m " <<
	"It's time to phase you suckers out!" << " ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " use blightbot against " << target << ", causing "
	<< this->_blightbotDamage << " points of damage! Energy: ";

}

void	FragTrap::clapInTheBox(std::string const &target) {

	std::cout << this->_color << this->_name << ">\033[0m " <<
	"Gotta blow up a bad guy, GOTTA BLOW UP A BAD GUY!" << " ";
	std::cout << "<" << this->_type << " " << this->_name << " attacks "
	<< target << ", using some box & causing " << this->_clapInTheBoxDamage <<
	" points of damage! Energy: ";

}

void	FragTrap::laserInferno(std::string const &target) {

	std::cout << this->_color << this->_name << ">\033[0m " <<
	"Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!" << " ";
	std::cout << "<" << this->_type << " " << this->_name
	<< " use lasers against " << target << ", causing "
	<< this->_laserInfernoDamage << " points of damage! Energy: ";

}

void	FragTrap::vaulthunter_dot_exe(std::string const &target) {

	std::srand(std::time(nullptr));

	if (this->_hitPoints == 0) {
		std::cout << "<" << this->_type << " " << this->_name
		<< " looks dead.>" << std::endl;
		return;
	}

	if (this->_energyPoints < 25) {
		std::cout << this->_color << this->_name << ">\033[0m " <<
		"Ooops! Somebody here needs tasty piece of energy..." << std::endl;
		return;
	}

	static int count = 0;

	int funNum = ((int)std::rand() + count * 5) % 4;

	void (FragTrap::*funcs[5])(std::string const &) = {
		&FragTrap::funzerker,
		&FragTrap::blightbot,
		&FragTrap::miniontrap,
		&FragTrap::clapInTheBox,
		&FragTrap::laserInferno
	};

	++count;

	(this->*funcs[funNum])(target);

	this->_energyPoints -= 25;

	std::cout << this->_energyPoints << " points.>" << std::endl;
}
