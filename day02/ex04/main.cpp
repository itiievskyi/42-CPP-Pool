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
#include <sstream>

static const std::string _operators[6] = {"+", "-", "*", "/", "(", ")"};

float doMath(std::string op, float a, float b)
{
	Fixed c;

	if (op == "/" && a == 0) {
		std::cout << "ERROR: You can't divide by 0!" << std::endl;
		std::exit(-1);
	}

	if (op == "+") {
		c = Fixed(a) + Fixed(b);
	} else if (op == "-") {
		c = Fixed(b) - Fixed(a);
	} else if (op == "*") {
		c = Fixed(a) * Fixed(b);
	} else if (op == "/") {
		c = Fixed(b) / Fixed(a);
	} else {
		std::cout << "INVALID OPERATOR" << std::endl;
	}

	return c.toFloat();
}

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

	int i = 0;
	std::stringstream ssin(expr);
	std::string arr[size];
	while (ssin.good() && i < size) {
		ssin >> arr[i];
		++i;
	}

	std::string operators[size];
	float numbers[size];
	int num = 0;
	int ops = 0;
	i = 0;

	while (i < size) {
		if (isFloat(arr[i])) {
			numbers[num] = std::stof(arr[i]);
			++num;
		} else if (isInvalid(arr[i])) {
			std::cout << "ERROR: Invalid operand: " << arr[i] << std::endl;
			return 0;
		} else if (arr[i] == "(") {
			if (i + 1 < size && (arr[i + 1] != "(") && !isInvalid(arr[i + 1])) {
				std::cout << "ERROR: Invalid expression" << std::endl;
				return 0;
			}
			operators[ops] = arr[i];
			++ops;
		} else if (arr[i] == "+" || arr[i] == "-") {
			if (ops == 0 || operators[ops - 1] == "(") {
				operators[ops] = arr[i];
				++ops;
			} else if (num < 2) {
				std::cout << "ERROR: Invalid number of operands" << std::endl;
				return 0;
			} else {
				numbers[num - 2] =
				doMath(operators[ops - 1], numbers[num - 1], numbers[num - 2]);
				--num;
				--ops;
				--i;
			}
		} else if (arr[i] == "*" || arr[i] == "/") {
			if (ops == 0 || operators[ops - 1] == "("
			|| operators[ops - 1] == "+" || operators[ops - 1] == "-") {
				operators[ops] = arr[i];
				++ops;
			} else if (num < 2) {
				std::cout << "ERROR: Invalid number of operands" << std::endl;
				return 0;
			} else {
				numbers[num - 2] =
				doMath(operators[ops - 1], numbers[num - 1], numbers[num - 2]);
				--num;
				--ops;
				--i;
			}
		} else if (arr[i] == ")") {
			while (operators[ops - 1] != "(" && ops > 0) {
				numbers[num - 2] =
				doMath(operators[ops - 1], numbers[num - 1], numbers[num - 2]);
				--num;
				--ops;
			}
			--ops;
			if (ops < 0) {
				std::cout << "ERROR: Invalid number of operands" << std::endl;
				return 0;
			}
		}
		++i;
	}

	if (num == 3 && ops == 2) {
		numbers[num - 2] =
		doMath(operators[ops - 1], numbers[num - 1], numbers[num - 2]);
		--num;
		--ops;
		--i;
	}
	if (num == 2 && ops == 1) {
		numbers[num - 2] =
		doMath(operators[ops - 1], numbers[num - 1], numbers[num - 2]);
		--num;
	} else if (!(num == 1 && ops == 0)) {
		std::cout << "ERROR: Invalid number of operands" << std::endl;
		return 0;
	}

	std::cout << numbers[0] << std::endl;

	return 0;
}
