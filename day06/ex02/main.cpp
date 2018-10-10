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

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <iomanip>

Base *generate(void) {

	std::srand(std::time(nullptr));

	int random = std::rand() % 3;

	if (random == 0) {
		std::cout << "Creating an object of class A..." << std::endl;
		return (new A());
	} else if (random == 1) {
		std::cout << "Creating an object of class B..." << std::endl;
		return (new B());
	} else {
		std::cout << "Creating an object of class C..." << std::endl;
		return (new C());
	}

	return nullptr;

}

void identify_from_pointer(Base *p) {

	if (dynamic_cast<A*>(p)) {
		std::cout << "This is object of class A!" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "This is object of class B!" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "This is object of class C!" << std::endl;
	}
}

void identify_from_reference(Base &p) {

	if (dynamic_cast<A*>(&p)) {
		std::cout << "This is object of class A!" << std::endl;
	} else if (dynamic_cast<B*>(&p)) {
		std::cout << "This is object of class B!" << std::endl;
	} else if (dynamic_cast<C*>(&p)) {
		std::cout << "This is object of class C!" << std::endl;
	}
}

int main(void) {

	Base *obj = generate();

	std::cout << "Identifying from pointer..." << std::endl;
	identify_from_pointer(obj);

	std::cout << "Identifying from reference..." << std::endl;
	identify_from_reference(*obj);

	return 0;
}
