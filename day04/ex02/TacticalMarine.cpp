/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:06:03 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/05 16:06:04 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void) {

	std::cout << "Tactical Marine ready for battle" << std::endl;

	return;
}

TacticalMarine::TacticalMarine(TacticalMarine const &src) {

	*this = src;

	return;
}

TacticalMarine &TacticalMarine::operator=(TacticalMarine const &src) {

	(void)src;

	return *this;
}

TacticalMarine::~TacticalMarine(void) {

	std::cout << "Aaargh ..." << std::endl;

	return;
}


ISpaceMarine *TacticalMarine::clone() const {

	TacticalMarine *unit = new TacticalMarine(*this);

	return unit;
}

void TacticalMarine::battleCry() const {

	std::cout << "For the holy PLOT !" << std::endl;

	return;
}

void TacticalMarine::rangedAttack() const {

	std::cout << "* attacks with bolter *" << std::endl;

	return;
}

void TacticalMarine::meleeAttack() const {

	std::cout << "* attacks with chainsword *" << std::endl;

	return;
}
