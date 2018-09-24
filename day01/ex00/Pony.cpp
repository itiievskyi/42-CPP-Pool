/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:40:50 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/24 16:40:52 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

Pony::Pony(std::string name) {

	this->_name = name;
	this->_height = 120;
	this->_color = "brown";
	std::cout << "The amazing pony named " << name << " was born!" << std::endl;
	return;
}

Pony::~Pony(void) {

	std::cout << "Pony named " << this->_name << " was killed" << std::endl;
	return;
}

std::string	Pony::getName(void) const {

	return this->_name;
}

std::string	Pony::getColor(void) const {

	return this->_color;
}

int			Pony::getHeight(void) const {

	return this->_height;
}

void		Pony::setColor(std::string color) {

	this->_color = color;
}

void		Pony::setHeight(int height) {

	this->_height = height;
}

void		Pony::introduce(void) const {

	std::cout << "Hello! My name is " << this->_name << ". I'm a beautiful "
	<< this->_height << " cm " << this->_color << " pony." << std::endl;
}
