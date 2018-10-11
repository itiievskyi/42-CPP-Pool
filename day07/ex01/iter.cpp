/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:15:01 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/11 11:15:02 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

template <typename T>
void print(T &element) {
	std::cout << element << std::endl;
}

template <typename T>
void increment(T &element) {
	++element;
}

template <typename T>
void selfmultiply(T &element) {
	element *= element;
}

template <typename T>
void iter(T *arr, size_t len, void (*f)(T &)) {
	for (size_t i = 0; i < len; i++) {
		f((arr)[i]);
	}
}

int main(void) {

	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::string strArray[] = {"hello", "world", "!"};

	Fixed fixedArray[] = {Fixed(0), Fixed(Fixed(15.01f) * Fixed(0.5f)), Fixed(42)};

	iter(array, 10, &selfmultiply);
	iter(array, 10, &print);

	std::cout << "**************************" << std::endl;

	iter(strArray, 3, &print);

	std::cout << "**************************" << std::endl;

	iter(fixedArray, 3, &print);
	iter(fixedArray, 3, &increment);
	iter(fixedArray, 3, &print);

	return 0;
}
