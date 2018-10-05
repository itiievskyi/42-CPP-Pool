/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:38:10 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:38:11 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon(("Power Fist"), 8, 50) {

	return;
}

PowerFist::PowerFist(PowerFist const &src) :
AWeapon(("Power Fist"), 8, 50) {

	*this = src;

	return;
}

PowerFist &PowerFist::operator=(PowerFist const &src) {

	AWeapon::operator=(src);

	return *this;;
}

PowerFist::~PowerFist(void) {

	return;
}

void PowerFist::attack(void) const {

	std::cout << "* pschhh... SBAM! *" << std::endl;

	return;
}
