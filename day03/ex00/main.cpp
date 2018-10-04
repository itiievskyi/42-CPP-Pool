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

int main(void) {

	FragTrap *toddy = new FragTrap("Toddy");
	FragTrap();
	FragTrap two = FragTrap();

	std::cout << "<Let the battle begin!>" << std::endl;

	toddy->rangedAttack("enemy1");
	toddy->meleeAttack("enemy1");

	toddy->takeDamage(50);
	toddy->takeDamage(10);

	toddy->beRepaired(20);
	toddy->beRepaired(70);
	toddy->beRepaired(20);
	toddy->beRepaired(20);

	toddy->meleeAttack("enemy2");
	toddy->takeDamage(30);
	toddy->meleeAttack("enemy2");
	toddy->beRepaired(20);

	toddy->vaulthunter_dot_exe("enemy3");
	toddy->vaulthunter_dot_exe("enemy3");
	toddy->vaulthunter_dot_exe("enemy3");
	toddy->vaulthunter_dot_exe("enemy3");

	toddy->takeDamage(50);
	toddy->beRepaired(20);

	toddy->meleeAttack("enemy4");
	toddy->meleeAttack("enemy4");
	toddy->takeDamage(30);
	toddy->meleeAttack("enemy4");

	toddy->vaulthunter_dot_exe("enemy4");
	toddy->beRepaired(10);

	toddy->takeDamage(120);

	toddy->rangedAttack("enemy1");
	toddy->meleeAttack("enemy1");
	toddy->takeDamage(10);
	toddy->beRepaired(20);

	std::cout << "<The battle finished>" << std::endl;

	delete toddy;

	return 0;
}
