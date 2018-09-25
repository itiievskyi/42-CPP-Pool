/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:39:17 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 09:39:18 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int		main(void) {

	ZombieEvent	firstEvent = ZombieEvent();
	ZombieEvent	secondEvent = ZombieEvent();

	Zombie		*hell = firstEvent.newZombie("Hell");
	hell->announce();

	Zombie		shaun = Zombie("Shaun", "graver");
	shaun.announce();

	Zombie		*random = secondEvent.randomChump();

	secondEvent.setZombieType("SuperZombie");

	Zombie		*rand_two = secondEvent.randomChump();
	rand_two->setPhrase("I WILL KILL ALL PEOPLE... ARHHHGHGH!");
	rand_two->announce();

	delete hell;
	delete random;
	delete rand_two;

	return 0;
}
