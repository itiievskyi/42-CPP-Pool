/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:47:18 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/08 12:47:19 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {

	Bureaucrat *bob = NULL;
	Bureaucrat *wrongBob = NULL;
	Bureaucrat *anotherBob = NULL;

	try {
		bob = new Bureaucrat("Bob", 1);
		wrongBob = new Bureaucrat("Wrong Bob", -1);
		anotherBob = new Bureaucrat("Another Bob", 1000);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		anotherBob = new Bureaucrat("Wrong Bob", 1000);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	bob != NULL ? (std::cout << *bob) : 0;
	wrongBob != NULL ? (std::cout << *wrongBob) : 0;
	anotherBob != NULL ? (std::cout << *anotherBob) : 0;

	try {
		bob->upGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	for (size_t i = 0; i < 151; i++) {
		try {
			bob->downGrade();
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}

	bob != NULL ? (std::cout << *bob) : 0;

	for (size_t i = 0; i < 151; i++) {
		try {
			bob->upGrade();
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}

	bob != NULL ? (std::cout << *bob) : 0;

	Bureaucrat *robert = new Bureaucrat(*bob);
	Bureaucrat *roberta = bob;
	std::cout << *robert << *roberta;

	return 0;
}
