/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:50:03 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:50:09 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Bob.hpp"

int main() {

/*
**	Standard tests
*/

	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

/*
**	Additional tests
*/

// Test for virtual destructor

	Victim *vic = new Peon("Jack");
	delete vic;

// Test for another derived class

	Victim *bob = new Bob("Bob");
	std::cout << *bob;
	robert.polymorph(*bob);
	delete bob;

	return 0;
}
