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
#include <cmath>

const int Fixed::_fract = 8;

Fixed::Fixed(void): _fixed(0) {

	return;
}

Fixed::Fixed(Fixed const &src) {

	*this = src;

	return;
}

Fixed::Fixed(const int intNum) {

	this->_fixed = intNum << _fract;

	return;
}

Fixed::Fixed(const float floatNum) {

	this->_fixed = std::roundf((floatNum) * (1 << this->_fract));

	return;
}

Fixed::~Fixed(void) {

	return;
}

Fixed &Fixed::operator=(Fixed const &src) {

	if (this != &src) {
		this->_fixed = src.getRawBits();
	}

	return *this;
}

Fixed &Fixed::operator++(void) {

	this->_fixed += 1;

	return *this;
}

Fixed &Fixed::operator--(void) {

	this->_fixed -= 1;

	return *this;
}

Fixed Fixed::operator++(int) {

	Fixed tmp(*this);
	operator++();

	return tmp;
}

Fixed Fixed::operator--(int) {

	Fixed tmp(*this);
	operator--();

	return tmp;
}

Fixed Fixed::operator+(Fixed const &src) const {

	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(Fixed const &src) const {

	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(Fixed const &src) const {

	return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(Fixed const &src) const {

	return Fixed(this->toFloat() / src.toFloat());
}

bool Fixed::operator==(Fixed const &src) const {

	return (this->toFloat() == src.toFloat());
}

bool Fixed::operator!=(Fixed const &src) const {

	return (this->toFloat() != src.toFloat());
}

bool Fixed::operator>(Fixed const &src) const {

	return (this->toFloat() > src.toFloat());
}

bool Fixed::operator<(Fixed const &src) const {

	return (this->toFloat() < src.toFloat());
}

bool Fixed::operator>=(Fixed const &src) const {

	return (this->toFloat() >= src.toFloat());
}

bool Fixed::operator<=(Fixed const &src) const {

	return (this->toFloat() <= src.toFloat());
}

Fixed &Fixed::max(Fixed &src1, Fixed &src2) {

	return (src1 > src2 ? src1 : src2);
}

const Fixed &Fixed::max(Fixed const &src1, Fixed const &src2) {

	return (src1 > src2 ? src1 : src2);
}

Fixed &Fixed::min(Fixed &src1, Fixed &src2) {

	return (src1 < src2 ? src1 : src2);
}

const Fixed &Fixed::min(Fixed const &src1, Fixed const &src2) {

	return (src1 < src2 ? src1 : src2);
}

int Fixed::getRawBits(void) const {

	return this->_fixed;
}

void Fixed::setRawBits(int const raw) {

	this->_fixed = raw;
}

float Fixed::toFloat(void) const {

	return (std::roundf(this->_fixed) / (1 << this->_fract));
}

int Fixed::toInt(void) const {

	return this->_fixed >> _fract;
}

std::ostream &operator<<(std::ostream &o, Fixed const &src) {

	o << src.toFloat();

	return o;
}
