/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:45:16 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 17:45:17 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Human.hpp"
#include <iostream>

Human::Human() {

	static int count = 1;

	this->_brain = new Brain();
	this->_name = "Bob #" + std::to_string(count);

	++count;

	return;
}

Human::~Human(void) {

	delete this->_brain;
	std::cout << this->_name << " died just after his brain did." << std::endl;

	return;
}

void Human::setName(std::string name) {

	this->_name = name;
}

std::string Human::getName(void) const {

	return this->_name;
}

std::string Human::identify(void) const {

	return (this->_brain)->identify();
}

Brain &Human::getBrain(void) {

	return *this->_brain;
}
