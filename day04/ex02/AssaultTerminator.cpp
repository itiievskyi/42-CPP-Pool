/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:06:27 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/05 16:06:28 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void) {

	std::cout << "* teleports from space *" << std::endl;

	return;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src) {

	*this = src;

	return;
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator const &src) {

	(void)src;

	return *this;
}

AssaultTerminator::~AssaultTerminator(void) {

	std::cout << "I'll be back ..." << std::endl;

	return;
}


ISpaceMarine *AssaultTerminator::clone() const {

	AssaultTerminator *unit = new AssaultTerminator(*this);

	return unit;
}

void AssaultTerminator::battleCry() const {

	std::cout << "This code is unclean. PURIFY IT !" << std::endl;

	return;
}

void AssaultTerminator::rangedAttack() const {

	std::cout << "* does nothing *" << std::endl;

	return;
}

void AssaultTerminator::meleeAttack() const {

	std::cout << "* attacks with chainfists *" << std::endl;

	return;
}
