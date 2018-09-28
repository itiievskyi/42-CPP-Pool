/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:24:36 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/27 10:24:37 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <sstream>

static const std::string _operators[6] = {"+", "-", "*", "/", "(", ")"};

bool isInvalid(std::string myString) {

	for (size_t i = 0; i < 6; i++) {
		if (myString == _operators[i]) {
			return false;
		}
	}

	return true;
}

bool isFloat(std::string myString) {

	std::istringstream iss(myString);
	float f;
	iss >> std::noskipws >> f;

	return iss.eof() && !iss.fail();
}

int main(int argc, char **argv) {

	int size = 0;

	if (argc != 2) {
		std::cout << "ERROR: you should specify one expression" << std::endl;
		return 0;
	}

	std::string expr = argv[1];
	expr.erase(0, expr.find_first_not_of(" "));
	expr.erase(expr.find_last_not_of(" ") + 1);

	if (expr.empty()) {
		std::cout << "ERROR: empty expression" << std::endl;
		return 0;
	}

	std::stringstream temp(expr);
	std::string buf;
	while (temp.good()) {
		temp >> buf;
		++size;
	}

	std::stringstream ssin(expr);
	std::string arr[size];
	std::string operators[size];
	float numbers[size];

	int num = 0;
	int ops = 0;
	int i = 0;

	while (ssin.good() && i < size) {
		ssin >> buf;
		if (isFloat(buf)) {
			numbers[num] = std::stof(buf);
			++num;
		} else if (isInvalid(buf)) {
			std::cout << "ERROR: Invalid expression: " << buf << std::endl;
			return 0;
		} else {
			operators[ops] = buf;
			++ops;
		}
		++i;
	}

	for(i = 0; i < num; i++) {
		std::cout << numbers[i] << std::endl;
	}

	for(i = 0; i < ops; i++) {
		std::cout << operators[i] << std::endl;
	}

//	std::cout << std::stof(arr[2]) + 3454.1 << '\n';

	return 0;
}
