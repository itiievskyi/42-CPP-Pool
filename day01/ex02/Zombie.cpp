/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:38:02 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 09:38:27 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name, std::string type) {

	this->_name = name;
	this->_type = type;
	this->_phrase = "Braiiiiiiinnnssss...";

	return;
}

Zombie::~Zombie(void) {

	std::cout << "AHRRR... NOOO... [" << this->_name << " dies]" << std::endl;

	return;
}

void		Zombie::announce(void) const {

	std::cout << this->_name << " (" << this->_type <<
	"): " << this->_phrase << std::endl;
}

std::string	Zombie::getName(void) const {

	return this->_name;
}

std::string	Zombie::getType(void) const {

	return this->_type;
}

std::string	Zombie::getPhrase(void) const {

	return this->_phrase;
}

void		Zombie::setPhrase(std::string phrase) {

	this->_phrase = phrase;
}
