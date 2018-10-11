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

#include "Array.tpp"
#include "Fixed.hpp"
#include "OutOfRangeException.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main(void) {

	std::srand(std::time(nullptr));

	Array<> empty;
	try {
		std::cout << empty[0] << std::endl;
	}
	catch (OutOfRangeException::OutOfRangeException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "**************************" << std::endl;

	Array<> intArr(5);

	for (int i = -1; i < 6; i++) {
		try {
			intArr[i] = std::rand() % INT_MAX;
		}
		catch (OutOfRangeException::OutOfRangeException &e) {
			std::cout << e.what() << std::endl;
		}
	}

	intArr[0] = 45;

	for (int i = 0; i < 6; i++) {
		try {
			std::cout << intArr[i] << std::endl;
		}
		catch (OutOfRangeException::OutOfRangeException &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "**************************" << std::endl;

	Array<int> cloneArray = intArr;

	for (int i = 0; i < 5; i++) {
		try {
			intArr[i] *= -1;
		}
		catch (OutOfRangeException::OutOfRangeException &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "Array comparing:" << std::endl;

	for (int i = 0; i < 5; i++) {
		try {
			std::cout << intArr[i] << "	|	" << cloneArray[i] << std::endl;
		}
		catch (OutOfRangeException::OutOfRangeException &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "**************************" << std::endl;

	Array<Fixed> fixedArray(3);
	fixedArray[0] = Fixed(4.50f * 23.04f);
	fixedArray[1] = Fixed(4.50f / 23.04f);

	for (int i = -1; i < 3; i++) {
		try {
			std::cout << fixedArray[i] << std::endl;
		}
		catch (OutOfRangeException::OutOfRangeException &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
