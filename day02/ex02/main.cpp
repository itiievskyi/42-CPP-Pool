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

int main(void) {

/*
** tests provided in task
*/

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

/*
** my own tests
*/

	std::cout << "\nADDITIONAL TESTS\n" << std::endl;
	Fixed const c( Fixed( 5.05f ) + Fixed( 0 ) );
	Fixed const d( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const e( Fixed( 5.05f ) / Fixed( -1.56f ) );
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	bool cmp;

	cmp = (a == b);
	std::cout << a << " == " << b << " -> "
	<< (!cmp ? "false" : "true") << std::endl;

	cmp = (a != b);
	std::cout << a << " != " << b << " -> "
	<< (!cmp ? "false" : "true") << std::endl;

	cmp = (Fixed(10.1016f) == b);
	std::cout << Fixed(10.1016f) << " == " << b << " -> "
	<< (!cmp ? "false" : "true") << std::endl;

	cmp = (Fixed(10.1016f) != b);
	std::cout << Fixed(10.1016f) << " != " << b << " -> "
	<< (!cmp ? "false" : "true") << std::endl;

	cmp = (e > b);
	std::cout << e << " > " << b << " -> "
	<< (!cmp ? "false" : "true") << std::endl;

	cmp = (e < b);
	std::cout << e << " < " << b << " -> "
	<< (!cmp ? "false" : "true") << std::endl;

	cmp = (c <= e);
	std::cout << c << " <= " << e << " -> "
	<< (!cmp ? "false" : "true") << std::endl;

	cmp = (c >= e);
	std::cout << c << " >= " << e << " -> "
	<< (!cmp ? "false" : "true") << std::endl;

	cmp = (c >= Fixed( 5.05f ));
	std::cout << c << " >= " << Fixed( 5.05f ) << " -> "
	<< (!cmp ? "false" : "true") << std::endl;

	std::cout << "e = " << e << ", c = " << c << ", min(e, c) = ";
	std::cout << Fixed::min(e, c) << std::endl;

	std::cout << "a = " << a << ", c = " << c << ", max(a, c) = ";
	std::cout << Fixed::max(a, c) << std::endl;

	return 0;
}
