/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:48:01 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/08 12:48:02 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name){

	if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		this->_grade = grade;
	}

	return;
}

Bureaucrat::Bureaucrat() : _name("Bureaucrat") {

	this->_grade = 42;

	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()) {

	*this = src;

	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {

	if (this != &src) {
		this->_grade = src.getGrade();
	}

	return *this;
}

Bureaucrat::~Bureaucrat(void) {

	return;
}

std::string Bureaucrat::getName(void) const {

	return this->_name;
}

void Bureaucrat::downGrade(void) {

	if (this->_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		++this->_grade;
	}
}

void Bureaucrat::signForm(Form &form) {

	if (form.getIsSigned()) {
		std::cout << this->_name << " cannot sign " << form.getName() <<
		" because this form is already signed." << std::endl;
	} else if (this->_grade > form.getSignGrade()) {
		std::cout << this->_name << " cannot sign " << form.getName() <<
		" because his grade is too low." << std::endl;
	} else {
		std::cout << this->_name << " signs " << form.getName() <<
		"." << std::endl;
	}

	return;
}

void Bureaucrat::upGrade(void) {

	if (this->_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		--this->_grade;
	}
}

int Bureaucrat::getGrade(void) const {

	return this->_grade;
}

// Too low

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {

	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &src) {

	*this = src;

	return;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {

	return;
}

Bureaucrat::GradeTooLowException  &Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *Bureaucrat::GradeTooLowException::what() const throw() {

	return "Cannot create or change object of class 'Bureaucrat': grade is too low (cannot exceed 150)";
}

// Too high

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {

	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &src) {

	*this = src;

	return;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {

	return;
}

Bureaucrat::GradeTooHighException  &Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *Bureaucrat::GradeTooHighException::what() const throw() {

	return "Cannot create or change object of class 'Bureaucrat': grade is too high (can't be < 1)";
}

// << Overloading

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src) {

	std::cout << src.getName() << ", bureaucrat grade "<< src.getGrade()
	<< std::endl;

	return o;
}
