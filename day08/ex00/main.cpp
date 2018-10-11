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

#include "easyfind.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

int main(void) {

	std::srand(std::time(nullptr));

	int a[30];
	std::cout << std::setw(10) << "Positions:";
	for (size_t i = 0; i < 30; i++) {
		std::cout << " | " << std::setw(2) << i;
	}
	std::cout << " | " << std::endl;
	std::cout << std::setw(10) << "Numbers:";
	for (size_t i = 0; i < 30; i++) {
		a[i] = (std::rand() + std::time(nullptr) / (i + 1)) % 10;
		std::cout << " | " << "\033[1;33m" << std::setw(2) << a[i] << "\033[0m";
	}
	std::cout << " | " << std::endl;


	std::vector<int> container(a, a + 30);
	int toFind = (std::rand() + std::time(nullptr) * 7) % 10;
	int position = easyfind(container, toFind);

	if (position < 0) {
		std::cout << "We can't find '" << toFind <<
		"' inside the above mentioned container." << std::endl;
	} else {
		std::cout << "The first occurance of '" << toFind <<
		"' in the above mentioned container was found at position "
		<< "\033[1;31m" << position << "\033[0m" << "."<< std::endl;
	}

	return 0;
}
