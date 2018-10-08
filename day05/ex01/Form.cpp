/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:50:55 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/08 16:50:56 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int signGrade, int execGrade) {

	this->_name = name;

	if (signGrade > 150 || execGrade > 150) {
		throw Form::GradeTooLowException();
	} else if (signGrade < 1 || execGrade < 1) {
		throw Form::GradeTooHighException();
	} else {
		this->_signGrade = signGrade;
		this->_execGrade = execGrade;
	}
	this->_isSigned = false;

	return;
}

Form::Form() {

	static int count = 1;

	this->_name = "Form #" + std::to_string(count);
	this->_signGrade = 42;
	this->_execGrade = 0;
	this->_isSigned = false;

	++count;

	return;
}

Form::Form(Form const &src) {

	*this = src;

	return;
}

Form &Form::operator=(Form const &src) {

	if (this != &src) {
		this->_name = src.getName();
		this->_signGrade = src.getSignGrade();
		this->_execGrade = src.getExecGrade();
		this->_isSigned = src.getIsSigned();
	}

	return *this;
}

Form::~Form(void) {

	return;
}

std::string Form::getName(void) const {

	return this->_name;
}

int Form::getSignGrade(void) const {

	return this->_signGrade;
}

int Form::getExecGrade(void) const {

	return this->_execGrade;
}

bool Form::getIsSigned(void) const {

	return this->_isSigned;
}

void Form::beSigned(Bureaucrat &signer) {

	if (this->_isSigned) {
		std::cout << "The form " << this->_name << " is already signed" << std::endl;
		signer.signForm(*this);
		return;
	}

	if (signer.getGrade() > this->_signGrade) {
		signer.signForm(*this);
		throw Form::GradeTooLowException();
	} else {
		signer.signForm(*this);
		this->_isSigned = true;
	}
}

// Too low

Form::GradeTooLowException::GradeTooLowException(void) {

	return;
}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &src) {

	*this = src;

	return;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {

	return;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(const GradeTooLowException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *Form::GradeTooLowException::what() const throw() {

	return "Cannot create or sign the form due to grade incoherence";
}

// Too high

Form::GradeTooHighException::GradeTooHighException(void) {

	return;
}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &src) {

	*this = src;

	return;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {

	return;
}

Form::GradeTooHighException  &Form::GradeTooHighException::operator=(const GradeTooHighException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *Form::GradeTooHighException::what() const throw() {

	return "Cannot create or change object of class 'Form': grade is too high (can't be < 1)";
}

// << Overloading

std::ostream &operator<<(std::ostream &o, Form const &src) {

	std::cout << "Form "<< src.getName() << " requires grade " <<
	src.getSignGrade() << " or higher to be signed and grade "
	<< src.getExecGrade() << " or higher to be executed. The form is ";
	if (src.getIsSigned()) {
		std::cout << "signed." << std::endl;
	} else {
		std::cout << "not signed." << std::endl;
	}

	return o;
}
