/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:43:56 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/10 17:43:57 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "You must provide 1 argument for conversion" << std::endl;
		return -1;
	}

	Converter num(argv[1]);

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "char: ";
	try {
		int ch = static_cast<int>(num);

		if (ch > 32 && ch < 127) {
			std::cout << "'" << static_cast<char>(ch) << "'" << std::endl;
		} else {
			std::cout << "Non displayable" << std::endl;
		}
	}
	catch (Converter::ImpossibleConversionException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Unknown exception" << std::endl;
	}

	std::cout << "int: ";
	try {
		std::cout << static_cast<int>(num) << std::endl;
	}
	catch (Converter::ImpossibleConversionException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Unknown exception" << std::endl;
	}

	std::cout << "float: ";
	try {
		std::cout << static_cast<float>(num) << "f" << std::endl;
	}
	catch (Converter::ImpossibleConversionException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Unknown exception" << std::endl;
	}

	std::cout << "double: ";
	try {
		std::cout << static_cast<double>(num) << std::endl;
	}
	catch (Converter::ImpossibleConversionException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Unknown exception" << std::endl;
	}

	return 0;
}
