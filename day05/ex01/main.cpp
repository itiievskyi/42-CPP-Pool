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
#include "Form.hpp"

int main(void) {

	Bureaucrat *bob = NULL;
	Bureaucrat *jim = NULL;
	Bureaucrat *mike = NULL;

	try {
		bob = new Bureaucrat("Bob", 1);
		jim = new Bureaucrat("Jim", 42);
		mike = new Bureaucrat("Mike", 120);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	Form *protocol = NULL;
	Form *blank = NULL;
	Form *contract = NULL;

	try {
		protocol = new Form("Protocol", 50, 50);
		contract = new Form("Contract", 1, 5);
		blank = new Form("Blank", 100, 151);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		blank = new Form("Blank", -1, 1);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		blank = new Form("Blank", 100, 100);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << *protocol;

	protocol->beSigned(*jim);
	protocol->beSigned(*bob);

	std::cout << *protocol;

	return 0;
}
