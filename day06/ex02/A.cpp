/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:14:49 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/10 20:14:50 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A(void) {

	return;
}

A::A(A &obj) {

	*this = obj;

	return;
}

A::~A(void) {

	return;
}

A &A::operator=(A const &r) {

	static_cast<void>(r);

	return (*this);
}
