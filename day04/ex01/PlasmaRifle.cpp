/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:37:56 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:37:56 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon(("Plasma Rifle"), 5, 21) {

	return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) :
AWeapon(("Plasma Rifle"), 5, 21) {

	*this = src;

	return;
}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &src) {

	AWeapon::operator=(src);

	return *this;;
}

PlasmaRifle::~PlasmaRifle(void) {

	return;
}

void PlasmaRifle::attack(void) const {

	std::cout << "* piouuu piouuu piouuu *" << std::endl;

	return;
}
