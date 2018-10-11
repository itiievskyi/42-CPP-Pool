/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:18:52 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/11 20:18:53 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(void) {

	this->_maxSize = 42;
	this->_actSize = 0;

	return;
}

Span::Span(unsigned int N) : _maxSize(N) {

	this->_actSize = 0;

	return;
}

Span::Span(Span const &src) {

	*this = src;

	return;
}

Span::~Span(void) {

	return;
}

Span &Span::operator=(Span const &src) {

	if (this != &src) {
		this->_maxSize = src.getMaxSize();
		this->_actSize = src.getActSize();
	}

	return *this;
}

unsigned int Span::getActSize(void) const {

	return this->_actSize;
}

unsigned int Span::getMaxSize(void) const {

	return this->_maxSize;
}

void Span::addNumber(int num) {

	if (this->_actSize == this->_maxSize) {
		throw Span::FullStoreException();
	} else {
		this->_v.push_back(num);
		++this->_actSize;
	}
}

int Span::longestSpan(void) const {

	double max = *max_element(this->_v.begin(), this->_v.end());
	double min = *min_element(this->_v.begin(), this->_v.end());

	if (this->_actSize < 2) {
		throw Span::TooFewException();
	} else if (min == max) {
		throw Span::IdenticalNumbersException();
	} else {
		return (max - min);
	}
}

int Span::shortestSpan(void) const {

	double max = *max_element(this->_v.begin(), this->_v.end());
	double min = *min_element(this->_v.begin(), this->_v.end());

	if (this->_actSize < 2) {
		throw Span::TooFewException();
	} else if (min == max) {
		throw Span::IdenticalNumbersException();
	}

	return -1;
}

// TOO FEW

Span::TooFewException::TooFewException(void) {

	return;
}

Span::TooFewException::TooFewException(const TooFewException &src) {

	*this = src;

	return;
}

Span::TooFewException::~TooFewException(void) throw() {

	return;
}

Span::TooFewException  &Span::TooFewException::operator=(const TooFewException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *Span::TooFewException::what() const throw() {

	return "ERROR: Too few elements to search the Span.";
}

// FULL STORE

Span::FullStoreException::FullStoreException(void) {

	return;
}

Span::FullStoreException::FullStoreException(const FullStoreException &src) {

	*this = src;

	return;
}

Span::FullStoreException::~FullStoreException(void) throw() {

	return;
}

Span::FullStoreException  &Span::FullStoreException::operator=(const FullStoreException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *Span::FullStoreException::what() const throw() {

	return "ERROR: Your integer container is full.";
}

// IDENTICAL NUMS

Span::IdenticalNumbersException::IdenticalNumbersException(void) {

	return;
}

Span::IdenticalNumbersException::IdenticalNumbersException(const IdenticalNumbersException &src) {

	*this = src;

	return;
}

Span::IdenticalNumbersException::~IdenticalNumbersException(void) throw() {

	return;
}

Span::IdenticalNumbersException  &Span::IdenticalNumbersException::operator=(const IdenticalNumbersException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *Span::IdenticalNumbersException::what() const throw() {

	return "ERROR: All numbers inside container are identical.";
}
