/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:39:31 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:39:32 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {

	std::cout << "Gaaah. Me want smash heads !" << std::endl;

	return;
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(170, "Super Mutant") {

	*this = src;

	return;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &src) {

	Enemy::operator=(src);

	return *this;;
}

SuperMutant::~SuperMutant(void) {

	std::cout << "Aaargh ..." << std::endl;

	return;
}

void SuperMutant::takeDamage(int damage) {

	int actualDamage = damage - 3;

	if (this->getHP() > 0 && actualDamage > 0) {
		if (actualDamage >= this->getHP()) {
			this->setHP(0);
		} else {
			this->setHP(this->getHP() - actualDamage);
		}
	}

	return;
}
