/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:51:10 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:51:10 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string name) {

	this->_name = name;

	std::cout << "Some random victim called " << this->_name << " just popped !"
	<< std::endl;

	return;
}

Victim::Victim(Victim const &src) {

	*this = src;

	std::cout << "Some random victim called " << this->_name << " just popped !"
	<< std::endl;

	return;
}

Victim &Victim::operator=(Victim const &src) {

	if (this != &src) {
		this->_name = src.getName();
	}

	return *this;
}

Victim::~Victim(void) {

	std::cout << "Victim " << this->_name
	<< " just died for no apparent reason !" << std::endl;

	return;
}

std::string Victim::getName(void) const {

	return this->_name;
}

void Victim::getPolymorphed(void) const {

	std::cout << this->_name << " has been turned into a cute little sheep !"
	<< std::endl;

	return;
}

std::ostream &operator<<(std::ostream &o, Victim const &src) {

	std::cout << "I'm " << src.getName() << " and I like otters !"
	<< std::endl;

	return o;
}
