/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bob.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:09:45 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:09:48 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bob.hpp"

Bob::Bob(std::string name) : Victim(name) {

	this->_name = name;

	std::cout << "Call me Robert please. Despite on my name." << std::endl;

	return;
}

Bob::Bob(Bob const &src) : Victim (src) {

	*this = src;

	std::cout << "Call me Robert please. Despite on my name." << std::endl;

	return;
}

Bob &Bob::operator=(Bob const &src) {

	if (this != &src) {
		this->_name = src.getName();
	}

	return *this;
}

Bob::~Bob(void) {

	std::cout << "Robert can't die!" << std::endl;

	return;
}
