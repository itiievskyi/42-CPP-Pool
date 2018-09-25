/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:59:52 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 15:59:53 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <iostream>

std::string		letter1 = "aoeiu";
std::string		letter2 = "wrtpsdfghklbnmc";

ZombieHorde::ZombieHorde(int N) {

	this->_size = N;

	if (N < 1) {
		std::cout << "It could be a good zombie horde but..." << std::endl;
	} else {
		this->_horde = new Zombie[N];
		for (int i = 0; i < N; i++) {
			this->_horde[i].setName(getRandomName());
		}
	}
	return;
}

ZombieHorde::~ZombieHorde(void) {

	delete [] this->_horde;;
	return;
}

std::string	ZombieHorde::getRandomName(void) {

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

	++count;

	return name;
}

void ZombieHorde::announce(void) const {

	for (int i = 0; i < this->_size; i++) {
		this->_horde[i].announce();
	}
}
