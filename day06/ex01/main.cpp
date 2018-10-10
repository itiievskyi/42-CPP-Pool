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

#include "Serialize.hpp"
#include <iostream>
#include <string>
#include <iomanip>

void *serialize(void) {

	char *str = new char[20];
	int i = -1;

	std::string set =
	"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	while (++i < 8) {
		str[i] = set[std::rand() % 62];
	}
	i = 7;
	while (++i < 12) {
		str[i] = static_cast<int>(std::rand());
	}
	i = 11;
	while (++i < 20) {
		str[i] = set[std::rand() % 62];
	}

	i = -1;

	std::cout << "String Data->s1: ";
	while (++i < 8) {
		std::cout << str[i];
	}
	std::cout << std::endl << "Integer Data->n: " << static_cast<int>(str[8]);
	i = 11;
	std::cout << std::endl << "String Data->s2: ";
	while (++i < 20) {
		std::cout << str[i];
	}
	std::cout << std::endl;

	return (reinterpret_cast<void*>(str));
}

Data *deserialize(void *raw) {

	Data *unSerialized = new Data;
	char *rawChar = reinterpret_cast<char*>(raw);

	int index = 0;
	int i = 0;

	while (++i < 9) {
		unSerialized->s1 += rawChar[index++];
	}
	unSerialized->n = static_cast<int>(rawChar[8]);
	i = 0;
	index += 4;
	while (++i < 9) {
		unSerialized->s2 += rawChar[index++];
	}

	return unSerialized;

}

int main(void) {

	void	*serialized;
	Data	*unSerialized;

	std::srand(std::time(nullptr));

	serialized = serialize();

	std::cout << "The heap address of the serialized data: " << serialized
	<< std::endl;

	unSerialized = deserialize(serialized);

	std::cout << "/*      After deserialization      */" << std::endl;
	std::cout << "String Data->s1: " << unSerialized->s1 << std::endl;
	std::cout << "Integer Data->n: " << unSerialized->n << std::endl;
	std::cout << "String Data->s2: " << unSerialized->s2 << std::endl;


	return 0;
}
