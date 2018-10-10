/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:15:22 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/10 20:15:23 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C(void) {

	return;
}

C::C(C &obj) {

	*this = obj;

	return;
}

C::~C(void) {

	return;
}

C &C::operator=(C const &r) {

	static_cast<void>(r);

	return (*this);
}
