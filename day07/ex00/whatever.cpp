/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 10:05:38 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/11 10:05:39 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

template <typename T>
T &max(T &x, T &y) {
	return (x > y ? x : y);
}

template <typename T>
T &min(T &x, T &y) {
	return (x < y ? x : y);
}

template <typename T>
void swap(T &x, T &y) {
	T temp = y;
	y = x;
	x = temp;
}

int main(void) {

	int x = 42;
	int y = 42;

	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << "**************************" << std::endl;

	::swap(x, y);
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x = " << &x << ", y = " << &y << std::endl;
	std::cout << "min(x, y) = " << ::min(x, y) << ", address: "
	<< &(::min(x, y)) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << ", address: "
	<< &(::min(x, y)) << std::endl;

	std::cout << "**************************" << std::endl;

	Fixed i = Fixed(10.51f);
	Fixed j = Fixed(10.59f);

	::swap(i, j);
	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "min(i, j) = " << ::min(i, j) << std::endl;
	std::cout << "max(i, j) = " << ::max(i, j) << std::endl;

	return 0;
}
