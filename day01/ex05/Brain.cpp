/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:44:55 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 17:44:57 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain(void) {

	std::stringstream buffer;
	buffer << this;

	this->_address = buffer.str();

	return;
}

Brain::~Brain(void) {

	std::cout << "Oh, this brain just died..." << std::endl;
	return;
}

std::string Brain::identify(void) const {

	return this->_address;
}
