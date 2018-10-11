/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutOfRangeException.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:27:31 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/11 15:27:34 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(void) {

	return;
}

OutOfRangeException::OutOfRangeException(const OutOfRangeException &src) {

	*this = src;

	return;
}

OutOfRangeException::~OutOfRangeException(void) throw() {

	return;
}

OutOfRangeException  &OutOfRangeException::operator=(const OutOfRangeException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *OutOfRangeException::what() const throw() {

	return "ERROR: You try to access the element that is out of array range";
}
