/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaGun.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:18:54 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/05 14:18:56 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MegaGun.hpp"

MegaGun::MegaGun(void) : AWeapon(("Mega Gun"), 10, 100) {

	return;
}

MegaGun::MegaGun(MegaGun const &src) :
AWeapon(("Mega Gun"), 10, 100) {

	*this = src;

	return;
}

MegaGun &MegaGun::operator=(MegaGun const &src) {

	AWeapon::operator=(src);

	return *this;;
}

MegaGun::~MegaGun(void) {

	return;
}

void MegaGun::attack(void) const {

	std::cout << "* BABANG! *" << std::endl;

	return;
}
