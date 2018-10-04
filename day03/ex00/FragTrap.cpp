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

	std::cout << "\033[1;31m" << this->_name << ">\033[0m " << "Hi! I'm "
	<< this->_name << "! Let's get this party started!" << std::endl;

	return;
}

FragTrap::FragTrap(FragTrap const &src) {

	*this = src;

	return;
}

FragTrap::FragTrap(void) {

	static int count = 0;

	this->_name = "Frag" + std::to_string(count);
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

	std::cout << "\033[1;31m" << this->_name << ">\033[0m " << "Hi! I'm "
	<< this->_name << "! Let's get this party started!" << std::endl;

	++count;

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
		std::cout << "<FR4G-TP " << this->_name <<
		"'s body is going to be recycled>" << std::endl;
	} else {
		std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
		"Hey, what the f... ------ " << " ";
		std::cout << "<FR4G-TP " << this->_name << " turned off.>" << std::endl;
	}

	return;
}

std::string FragTrap::getName(void) {

	return this->_name;
}

unsigned int FragTrap::getMeleeAttackDamage(void) {

	return this->_meleeAttackDamage;
}

unsigned int FragTrap::getRangedAttackDamage(void) {

	return this->_rangedAttackDamage;
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

void	FragTrap::checkLevel(void) {

	if (this->_accumulatedDamage / 100 >= this->_level) {
		++this->_level;
		this->_energyPoints = this->_maxEnergyPoints;
		std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
		"Now I will dominate!" << " ";
		std::cout << "<FR4G-TP " << this->_name << " reaches level " <<
		this->_level << "! ";
		std::cout << "Energy: " << this->_energyPoints << " points.>"
		<< std::endl;
	}
}

void	FragTrap::rangedAttack(std::string const &target) {

	if (this->_hitPoints == 0) {
		std::cout << "<FR4G-TP " << this->_name << " looks dead.>" << std::endl;
		return;
	}
	std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
	"That looks like it hurts!" << " ";
	std::cout << "<FR4G-TP " << this->_name << " attacks " << target
	<< " at range, causing " << this->_rangedAttackDamage <<
	" points of damage!>" << std::endl;

	this->_accumulatedDamage += this->_rangedAttackDamage;
	this->checkLevel();
}

void	FragTrap::meleeAttack(std::string const &target) {

	if (this->_hitPoints == 0) {
		std::cout << "<FR4G-TP " << this->_name << " looks dead.>" << std::endl;
		return;
	}
	std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
	"Heyyaaaaaah!" << " ";
	std::cout << "<FR4G-TP " << this->_name << " performs melee attack against "
	<< target << ", causing " << this->_meleeAttackDamage <<
	" points of damage!>" << std::endl;

	this->_accumulatedDamage += this->_meleeAttackDamage;
	this->checkLevel();
}

void	FragTrap::takeDamage(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << "<FR4G-TP " << this->_name << " looks dead.>" << std::endl;
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
		std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
		"Argh arghargh death gurgle gurglegurgle urgh... death." << " ";
		std::cout << "<FR4G-TP " << this->_name << " takes "
		<< this->_hitPoints << " points of damage. HP: ";
		this->_hitPoints = 0;
		std::cout << this->_hitPoints << " points. Armor: ";
		std::cout << this->_armorDamageReduction << " points.>" << std::endl;
	} else if (actualAmount == 0) {
		std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
		"HA! HAA! HAAAA!" << " ";
		std::cout << "<FR4G-TP " << this->_name << " takes "
		<< actualAmount << " points of damage. HP: " << this->_hitPoints
		<< " points. Armor: ";
		std::cout << this->_armorDamageReduction << " points.>" << std::endl;
	} else {
		this->_hitPoints -= actualAmount;
		std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
		"Why do I even feel pain?!" << " ";
		std::cout << "<FR4G-TP " << this->_name << " takes "
		<< actualAmount << " points of damage. HP: " << this->_hitPoints
		<< " points. Armor: ";
		std::cout << this->_armorDamageReduction << " points.>" << std::endl;
	}
}

void	FragTrap::beRepaired(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << "<FR4G-TP " << this->_name << " looks dead.>" << std::endl;
		return;
	}

	if (this->_energyPoints == 0) {
		std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
		"Ooops! Somebody here needs tasty piece of energy..." << std::endl;
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

	std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
	"Sweet life juice!" << " ";
	if (actualAmount >= this->_maxHitPoints - this->_hitPoints) {
		std::cout << "<FR4G-TP " << this->_name << " restores "
		<< this->_maxHitPoints - this->_hitPoints << " hit points. HP: ";
		this->_hitPoints = _maxHitPoints;
		std:: cout << this->_hitPoints << " points. Energy: "
		<< this->_energyPoints << " points.>" << std::endl;
	} else {
		this->_hitPoints += actualAmount;
		std::cout << "<FR4G-TP " << this->_name << " restores "
		<< actualAmount << " hit points. HP: "
		<< this->_hitPoints << " points Energy: "
		<< this->_energyPoints << " points.>" << std::endl;
	}
}

void	FragTrap::funzerker(std::string const &target) {

	std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
	"Don't ask me where this ammo's coming from!" << " ";
	std::cout << "<FR4G-TP " << this->_name << " use funzerker against "
	<< target << ", causing " << this->_funzerkerDamage <<
	" points of damage! Energy: ";

}

void	FragTrap::miniontrap(std::string const &target) {

	std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
	"Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!"
	<< " ";
	std::cout << "<FR4G-TP " << this->_name << " sets the minion trap against "
	<< target << ", causing " << this->_miniontrapDamage <<
	" points of damage! Energy: ";

}

void	FragTrap::blightbot(std::string const &target) {

	std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
	"It's time to phase you suckers out!" << " ";
	std::cout << "<FR4G-TP " << this->_name << " use blightbot against "
	<< target << ", causing " << this->_blightbotDamage <<
	" points of damage! Energy: ";

}

void	FragTrap::clapInTheBox(std::string const &target) {

	std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
	"Gotta blow up a bad guy, GOTTA BLOW UP A BAD GUY!" << " ";
	std::cout << "<FR4G-TP " << this->_name << " attacks "
	<< target << ", using some box & causing " << this->_clapInTheBoxDamage <<
	" points of damage! Energy: ";

}

void	FragTrap::laserInferno(std::string const &target) {

	std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
	"Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!" << " ";
	std::cout << "<FR4G-TP " << this->_name << " use lasers against "
	<< target << ", causing " << this->_laserInfernoDamage <<
	" points of damage! Energy: ";

}

void	FragTrap::vaulthunter_dot_exe(std::string const &target) {

	std::srand(std::time(nullptr));

	if (this->_hitPoints == 0) {
		std::cout << "<FR4G-TP " << this->_name << " looks dead.>" << std::endl;
		return;
	}

	if (this->_energyPoints < 25) {
		std::cout << "\033[1;31m" << this->_name << ">\033[0m " <<
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
