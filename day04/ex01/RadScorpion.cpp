/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:39:50 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:39:50 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion") {

	std::cout << "* click click click *" << std::endl;

	return;
}

RadScorpion::RadScorpion(RadScorpion const &src) : Enemy(80, "RadScorpion") {

	*this = src;

	return;
}

RadScorpion &RadScorpion::operator=(RadScorpion const &src) {

	Enemy::operator=(src);

	return *this;;
}

RadScorpion::~RadScorpion(void) {

	std::cout << "* SPROTCH *" << std::endl;

	return;
}
