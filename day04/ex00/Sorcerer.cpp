/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:50:50 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:50:51 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) {

	this->_name = name;
	this->_title = title;

	std::cout << this->_name << ", "<< this->_title << ", is born !"
	<< std::endl;

	return;
}

Sorcerer::Sorcerer(Sorcerer const &src) {

	*this = src;

	std::cout << this->_name << ", "<< this->_title << ", is born !"
	<< std::endl;

	return;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &src) {

	if (this != &src) {
		this->_name = src.getName();
		this->_title = src.getTitle();
	}

	return *this;
}

Sorcerer::~Sorcerer(void) {

	std::cout << this->_name << ", "<< this->_title
	<< ", is dead. Consequences will never be the same !" << std::endl;

	return;
}

std::string Sorcerer::getName(void) const {

	return this->_name;
}

std::string Sorcerer::getTitle(void) const {

	return this->_title;
}

void Sorcerer::polymorph(Victim const &src) const {

	src.getPolymorphed();

	return;
}

std::ostream &operator<<(std::ostream &o, Sorcerer const &src) {

	std::cout << "I am " << src.getName() << ", "<< src.getTitle() <<
	", and I like ponies !" << std::endl;

	return o;
}
