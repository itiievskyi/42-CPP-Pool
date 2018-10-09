/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:23:55 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 15:23:56 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {

	this->_funcs[0] = &Intern::_newPresidentialPardonForm;
	this->_funcs[1] = &Intern::_newRobotomyRequestForm;
	this->_funcs[2] = &Intern::_newShrubberyCreationForm;

	this->_types[0] = "presidental pardon";
	this->_types[1] = "robotomy request";
	this->_types[2] = "shrubbery creation";

	return;
}

Intern::Intern(Intern const &src) {

	*this = src;

	return;
}

Intern &Intern::operator=(Intern const &src) {

	static_cast <void>(src);

	return *this;
}

Intern::~Intern(void) {

	return;
}

Form	*Intern::_newPresidentialPardonForm(std::string target) {

	return (new PresidentialPardonForm(target));
}

Form	*Intern::_newRobotomyRequestForm(std::string target) {

	return (new RobotomyRequestForm(target));
}

Form	*Intern::_newShrubberyCreationForm(std::string target) {

	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeForm(std::string type, std::string target) {

	Form *obj;

	for (int i = 0; i < NUM_OF_FUNCS; i++) {
		if (this->_types[i] == type) {
			obj = (this->*_funcs[i])(target);
			std::cout << "Intern creates a " << obj->getName() << " form"
			<< std::endl;
			return obj;
		}
	}

	std::cout << "Intern can't create a form of the specified type" << std::endl;

	return nullptr;
}
