/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:15:10 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/10 20:15:11 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B(void) {

	return;
}

B::B(B &obj) {

	*this = obj;

	return;
}

B::~B(void) {

	return;
}

B &B::operator=(B const &r) {

	static_cast<void>(r);

	return (*this);
}
