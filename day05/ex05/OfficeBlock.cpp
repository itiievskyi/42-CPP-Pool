/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:50:41 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 16:50:45 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) {

	this->_intern = nullptr;
	this->_signer = nullptr;
	this->_executer = nullptr;

	return;
}

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executer) {

	this->_intern = &intern;
	this->_signer = &signer;
	this->_executer = &executer;

	return;
}

OfficeBlock::~OfficeBlock(void) {

	return;
}

void OfficeBlock::setIntern(Intern &intern) {

	this->_intern = &intern;

	return;
}

void OfficeBlock::setSigner(Bureaucrat &signer) {

	this->_signer = &signer;

	return;
}

void OfficeBlock::setExecutor(Bureaucrat &executer) {

	this->_executer = &executer;

	return;
}

void OfficeBlock::doBureaucracy(std::string type, std::string target) {

	if (!this->_intern) {
		throw OfficeBlock::NoInternException();
	}
	if (!this->_signer) {
		throw OfficeBlock::NoSignerException();
	}
	if (!this->_executer) {
		throw OfficeBlock::NoExecutorException();
	}

	Form *form = this->_intern->makeForm(type, target);

	if (((this->_signer->getGrade()) > form->getSignGrade())) {
		throw OfficeBlock::GradeTooLowToSignException();
	}
	if (((this->_executer->getGrade()) > form->getExecGrade())) {
		throw OfficeBlock::GradeTooLowToExecuteException();
	}

	this->_signer->signForm(*form);
	this->_executer->executeForm(*form);

	std::cout << "Uh... We've finished. Let's drink some coffee!" << std::endl;

	return;
}

// No Intern

OfficeBlock::NoInternException::NoInternException(void) {

	return;
}

OfficeBlock::NoInternException::NoInternException(const NoInternException &src) {

	*this = src;

	return;
}

OfficeBlock::NoInternException::~NoInternException(void) throw() {

	return;
}

OfficeBlock::NoInternException  &OfficeBlock::NoInternException::operator=(const NoInternException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *OfficeBlock::NoInternException::what() const throw() {

	return "Ooops... It seems like you don't have an intern in your office.";
}

// No Signer

OfficeBlock::NoSignerException::NoSignerException(void) {

	return;
}

OfficeBlock::NoSignerException::NoSignerException(const NoSignerException &src) {

	*this = src;

	return;
}

OfficeBlock::NoSignerException::~NoSignerException(void) throw() {

	return;
}

OfficeBlock::NoSignerException  &OfficeBlock::NoSignerException::operator=(const NoSignerException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *OfficeBlock::NoSignerException::what() const throw() {

	return "Ooops... It seems like you don't have a signer in your office.";
}

// No Executor

OfficeBlock::NoExecutorException::NoExecutorException(void) {

	return;
}

OfficeBlock::NoExecutorException::NoExecutorException(const NoExecutorException &src) {

	*this = src;

	return;
}

OfficeBlock::NoExecutorException::~NoExecutorException(void) throw() {

	return;
}

OfficeBlock::NoExecutorException  &OfficeBlock::NoExecutorException::operator=(const NoExecutorException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *OfficeBlock::NoExecutorException::what() const throw() {

	return "Ooops... It seems like you don't have an executor in your office.";
}

// Too low to sign

OfficeBlock::GradeTooLowToSignException::GradeTooLowToSignException(void) {

	return;
}

OfficeBlock::GradeTooLowToSignException::GradeTooLowToSignException(const GradeTooLowToSignException &src) {

	*this = src;

	return;
}

OfficeBlock::GradeTooLowToSignException::~GradeTooLowToSignException(void) throw() {

	return;
}

OfficeBlock::GradeTooLowToSignException &OfficeBlock::GradeTooLowToSignException::operator=(const GradeTooLowToSignException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *OfficeBlock::GradeTooLowToSignException::what() const throw() {

	return "The form can't be signed because the signer's level is too low";
}

// Too low to execute

OfficeBlock::GradeTooLowToExecuteException::GradeTooLowToExecuteException(void) {

	return;
}

OfficeBlock::GradeTooLowToExecuteException::GradeTooLowToExecuteException(const GradeTooLowToExecuteException &src) {

	*this = src;

	return;
}

OfficeBlock::GradeTooLowToExecuteException::~GradeTooLowToExecuteException(void) throw() {

	return;
}

OfficeBlock::GradeTooLowToExecuteException &OfficeBlock::GradeTooLowToExecuteException::operator=(const GradeTooLowToExecuteException &src) {

	static_cast <void> (src);

	return *this;
}

const char    *OfficeBlock::GradeTooLowToExecuteException::what() const throw() {

	return "The form can't be executed because the executer's level is too low";
}
