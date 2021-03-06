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

	Form *obj = nullptr;

	std::string types[3] = {
		"presidental pardon",
		"robotomy request",
		"shrubbery creation"
	};

	if (type == types[0]) {
		obj = Intern::_newPresidentialPardonForm(target);
		std::cout << "Intern creates a " << *obj;
		return obj;
	} else if (type == types[1]) {
		obj = Intern::_newRobotomyRequestForm(target);
		std::cout << "Intern creates a " << *obj;
		return obj;
	} else if (type == types[2]) {
		obj = Intern::_newShrubberyCreationForm(target);
		std::cout << "Intern creates a " << *obj;
		return obj;
	} else {
		throw Intern::UknownFormException();
	}

	return nullptr;
}

// Uknown form

Intern::UknownFormException::UknownFormException(void) {

	return;
}

Intern::UknownFormException::UknownFormException(const UknownFormException &src) {

	*this = src;

	return;
}

Intern::UknownFormException::~UknownFormException(void) throw() {

	return;
}

Intern::UknownFormException &Intern::UknownFormException::operator=(const UknownFormException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *Intern::UknownFormException::what() const throw() {

	return "Intern can't create a form of the specified type";
}
