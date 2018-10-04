/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:51:25 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:51:25 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name) {

	this->_name = name;

	std::cout << "Zog zog." << std::endl;

	return;
}

Peon::Peon(Peon const &src) : Victim (src) {

	*this = src;

	std::cout << "Zog zog." << std::endl;

	return;
}

Peon &Peon::operator=(Peon const &src) {

	if (this != &src) {
		this->_name = src.getName();
	}

	return *this;
}

void Peon::getPolymorphed(void) const {

	std::cout << this->_name << " has been turned into a pink pony !"
	<< std::endl;

	return;
}

Peon::~Peon(void) {

	std::cout << "Bleuark..." << std::endl;

	return;
}
