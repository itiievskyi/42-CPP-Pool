/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:35:34 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/11 18:35:36 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

int main(void) {

	std::srand(std::time(nullptr));

	Span sp = Span(5);

	try {
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
	}
	catch (Span::FullStoreException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		int span = sp.longestSpan();
		std::cout << "The longest span is: " << span << std::endl;
	}
	catch (Span::IdenticalNumbersException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Span::TooFewException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		int span = sp.shortestSpan();
		std::cout << "The shortest span is: " << span << std::endl;
	}
	catch (Span::IdenticalNumbersException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Span::TooFewException &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
