/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:24:36 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/27 10:24:37 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int main(void) {

	FragTrap *fraggy = new FragTrap("Fraggy");
	NinjaTrap *ninja = new NinjaTrap("Ninja");
	ScavTrap *scavvvvvvvvy = new ScavTrap("Scavvvvvvvvy");

	std::cout << "<Let the battle begin!>" << std::endl;

	fraggy->meleeAttack(ninja->getName());
	ninja->takeDamage(fraggy->getMeleeAttackDamage());

	scavvvvvvvvy->challengeNewcomer(fraggy->getName());

	ninja->meleeAttack(fraggy->getName());
	fraggy->takeDamage(ninja->getMeleeAttackDamage());

	fraggy->rangedAttack(scavvvvvvvvy->getName());
	scavvvvvvvvy->takeDamage(fraggy->getRangedAttackDamage());

	ninja->rangedAttack(fraggy->getName());
	fraggy->takeDamage(ninja->getRangedAttackDamage());

	ninja->beRepaired(50);

	scavvvvvvvvy->meleeAttack(fraggy->getName());
	fraggy->takeDamage(scavvvvvvvvy->getMeleeAttackDamage());

	fraggy->beRepaired(100);

	fraggy->vaulthunter_dot_exe(scavvvvvvvvy->getName());

	fraggy->meleeAttack(scavvvvvvvvy->getName());
	scavvvvvvvvy->takeDamage(fraggy->getMeleeAttackDamage());
	fraggy->meleeAttack(scavvvvvvvvy->getName());
	scavvvvvvvvy->takeDamage(fraggy->getMeleeAttackDamage());
	fraggy->meleeAttack(scavvvvvvvvy->getName());
	scavvvvvvvvy->takeDamage(fraggy->getMeleeAttackDamage());
	fraggy->vaulthunter_dot_exe(scavvvvvvvvy->getName());
	scavvvvvvvvy->takeDamage(40);
	fraggy->meleeAttack(scavvvvvvvvy->getName());
	scavvvvvvvvy->takeDamage(fraggy->getMeleeAttackDamage());

	ninja->meleeAttack(fraggy->getName());
	fraggy->takeDamage(ninja->getMeleeAttackDamage());
	ninja->rangedAttack(fraggy->getName());
	fraggy->takeDamage(ninja->getRangedAttackDamage());

	ninja->beRepaired(50);

	fraggy->vaulthunter_dot_exe(ninja->getName());
	ninja->takeDamage(40);

	ClapTrap testClap;

	ninja->ninjaShoebox(*fraggy);
	ninja->ninjaShoebox(*scavvvvvvvvy);
	ninja->ninjaShoebox(testClap);
	ninja->ninjaShoebox(*ninja);

	std::cout << "<The battle finished>" << std::endl;

	ScavTrap *twinScav = scavvvvvvvvy;
	twinScav->challengeNewcomer(fraggy->getName());

	delete fraggy;
	delete scavvvvvvvvy;
	delete ninja;

	return 0;
}
