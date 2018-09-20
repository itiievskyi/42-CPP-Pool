/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:19:01 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/20 15:19:02 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

int		main(void) {

	std::string		buf;
	Contact 		instance[8];

	std::cout << "====== Welcome to the Awesome Phonebook! ======" << std::endl;
	std::cout << " Type an appropriate command to perform action" << std::endl;
	std::cout << "============= ADD / SEARCH / EXIT =============" << std::endl;
	std::cin >> buf;

	return 0;

}
