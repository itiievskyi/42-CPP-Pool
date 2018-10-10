/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:43:41 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/10 17:43:42 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(std::string target) : _target(target){

	return;
}

Converter::Converter(Converter const &src) : _target(src.getTarget()) {

	*this = src;

	return;
}

Converter &Converter::operator=(Converter const &src) {

	if (this != &src) {
		this->_target = src.getTarget();
	}

	return *this;
}

Converter::~Converter(void) {

	return;
}



Converter::operator int() const {

	int	num;

	try {
		num = std::stoi(this->_target);
	}
	catch (std::exception &e) {
		throw ImpossibleConversionException();
	}

	return num;
}

Converter::operator float() const {

	float	num;

	try {
		num = std::stof(this->_target);
	}
	catch (std::exception &e) {
		throw ImpossibleConversionException();
	}

	return num;
}

Converter::operator double() const {

	double	num;

	try {
		num = std::stod(this->_target);
	}
	catch (std::exception &e) {
		throw ImpossibleConversionException();
	}

	return num;
}

std::string Converter::getTarget(void) const {

	return this->_target;
}

Converter::ImpossibleConversionException::ImpossibleConversionException(void) {

	return;
}

Converter::ImpossibleConversionException::ImpossibleConversionException(const ImpossibleConversionException &src) {

	*this = src;

	return;
}

Converter::ImpossibleConversionException::~ImpossibleConversionException(void) throw() {

	return;
}

Converter::ImpossibleConversionException  &Converter::ImpossibleConversionException::operator=(const ImpossibleConversionException &src) {

	static_cast<void>(src);

	return *this;
}

const char    *Converter::ImpossibleConversionException::what() const throw() {

	return "impossible";
}
