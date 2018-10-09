/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:47:18 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/08 12:47:19 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "CentralBureaucracy.hpp"
#include "OfficeBlock.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

	std::string		letter1 = "aoeiu";
	std::string		letter2 = "wrtpsdfghklbnmc";

	CentralBureaucracy	bureau;

	for (int i = 0; i < 22; i++) {

		int length = ((int)std::rand() + i * 5) % 8 + 2;
		std::string name = "         ";

		name.resize(length);

		for (int i = 0; i < length; i++) {
			if (i == 0) {
				name[i] =
				std::toupper(letter2[(std::rand() + i) % letter2.length()]);
			} else if (i % 2 == 0) {
				name[i] = letter2[(std::rand() + i) % letter2.length()];
			} else {
				name[i] = letter1[(std::rand() + i) % letter1.length()];
			}
		}
		name[length] = '\0';
		Bureaucrat *temp = new Bureaucrat(name, std::rand() % 149 + 1);
		bureau.feedBureaucrat(temp);

	}

	std::cout << "*****************************************" << std::endl;

	bureau.doBureaucracy();

	std::cout << "*****************************************" << std::endl;

	for (int i = 0; i < 30; i++) {

		int length = ((int)std::rand() + i * 5) % 8 + 2;
		std::string name = "         ";

		name.resize(length);

		for (int i = 0; i < length; i++) {
			if (i == 0) {
				name[i] =
				std::toupper(letter2[(std::rand() + i) % letter2.length()]);
			} else if (i % 2 == 0) {
				name[i] = letter2[(std::rand() + i) % letter2.length()];
			} else {
				name[i] = letter1[(std::rand() + i) % letter1.length()];
			}
		}
		name[length] = '\0';
		bureau.queueUp(name);

	}

	bureau.doBureaucracy();

	std::cout << "*****************************************" << std::endl;

	bureau.doBureaucracy();

	return 0;
}
