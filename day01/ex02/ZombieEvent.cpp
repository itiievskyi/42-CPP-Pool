/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:38:56 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 09:38:57 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <string>

std::string		letter1 = "aoeiu";
std::string		letter2 = "wrtpsdfghklbnmc";

ZombieEvent::ZombieEvent(void) {

	this->_zombieType = "regular zombie";
	return;
}

ZombieEvent::~ZombieEvent(void) {

	return;
}

void		ZombieEvent::setZombieType(std::string type) {

	this->_zombieType = type;
}

std::string	ZombieEvent::getZombieType(void) const {

	return this->_zombieType;
}

Zombie*		ZombieEvent::newZombie(std::string name) {

	Zombie* zomb = new Zombie(name, this->_zombieType);

	return (zomb);
}

Zombie*		ZombieEvent::randomChump(void) {

	std::srand(std::time(nullptr));

	static int count = 0;

	int length = ((int)std::rand() + count * 5) % 8 + 2;
	std::string name = "         ";

	name.resize(length);

	for (int i = 0; i < length; i++) {
		if (i == 0) {
			name[i] =
			std::toupper(letter2[(std::rand() + count) % letter2.length()]);
		} else if (i % 2 == 0) {
			name[i] = letter2[(std::rand() + count)% letter2.length()];
		} else {
			name[i] = letter1[(std::rand() + count)% letter1.length()];
		}
	}
	name[length] = '\0';

	Zombie* zomb = new Zombie(name, this->_zombieType);
	zomb->announce();

	count += 1;
	return (zomb);
}
