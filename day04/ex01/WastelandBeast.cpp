/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WastelandBeast.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:23:20 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/05 14:23:22 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WastelandBeast.hpp"

WastelandBeast::WastelandBeast(void) : Enemy(125, "WastelandBeast") {

	std::cout << "* AAAAAAAAAAAAAAAAAAA *" << std::endl;

	return;
}

WastelandBeast::WastelandBeast(WastelandBeast const &src) :
Enemy(80, "WastelandBeast") {

	*this = src;

	return;
}

WastelandBeast &WastelandBeast::operator=(WastelandBeast const &src) {

	Enemy::operator=(src);

	return *this;;
}

WastelandBeast::~WastelandBeast(void) {

	std::cout << "* ZZZZZZZZZZZZZZZZZZ *" << std::endl;

	return;
}
