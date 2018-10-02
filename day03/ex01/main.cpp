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

int main(void) {

	FragTrap *fraggy = new FragTrap("Fraggy");
	ScavTrap *scavvy = new ScavTrap("Scavvy");
	ScavTrap *scavvvvvvvvy = new ScavTrap("Scavvvvvvvvy");

	std::cout << "<Let the battle begin!>" << std::endl;

	scavvy->challengeNewcomer(fraggy->getName());

	fraggy->meleeAttack(scavvy->getName());
	scavvy->takeDamage(fraggy->getMeleeAttackDamage());

	scavvvvvvvvy->challengeNewcomer(fraggy->getName());

	scavvy->rangedAttack(fraggy->getName());
	fraggy->takeDamage(scavvy->getRangedAttackDamage());

	fraggy->rangedAttack(scavvvvvvvvy->getName());
	scavvvvvvvvy->takeDamage(fraggy->getRangedAttackDamage());

	scavvy->rangedAttack(fraggy->getName());
	fraggy->takeDamage(scavvy->getRangedAttackDamage());

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

	scavvy->rangedAttack(fraggy->getName());
	fraggy->takeDamage(scavvy->getRangedAttackDamage());
	scavvy->rangedAttack(fraggy->getName());
	fraggy->takeDamage(scavvy->getRangedAttackDamage());

	fraggy->vaulthunter_dot_exe(scavvy->getName());
	scavvy->takeDamage(40);

	std::cout << "<The battle finished>" << std::endl;

	delete fraggy;
	delete scavvy;
	delete scavvvvvvvvy;

	return 0;
}
