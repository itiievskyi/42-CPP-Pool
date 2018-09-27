/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:24:18 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/27 10:24:19 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract = 8;

Fixed::Fixed(void): _fixed(0) {

	std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::Fixed(Fixed const &src) {

	std::cout << "Copy constructor called" << std::endl;

	*this = src;

	return;
}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;

	return;
}

Fixed &Fixed::operator=(Fixed const &src) {

	std::cout << "Assignation operator called" << std::endl;

	if (this != &src) {
		this->_fixed = src.getRawBits();
	}

	return *this;
}

int Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;

	return this->_fixed;
}

void Fixed::setRawBits(int const raw) {

	this->_fixed = raw;
}
