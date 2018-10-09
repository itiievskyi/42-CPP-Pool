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
#include "OfficeBlock.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

	Intern      idiotOne;
	Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat  bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;

	try {
		ob.doBureaucracy("presidental pardon", "Bender");
	}
	catch (OfficeBlock::NoInternException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecutorException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Intern::UknownFormException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToSignException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToExecuteException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	ob.setIntern(idiotOne);

	try {
		ob.doBureaucracy("presidental pardon", "Bender");
	}
	catch (OfficeBlock::NoInternException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecutorException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Intern::UknownFormException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToSignException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToExecuteException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	ob.setSigner(bob);

	try {
		ob.doBureaucracy("presidental pardon", "Bender");
	}
	catch (OfficeBlock::NoInternException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecutorException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Intern::UknownFormException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToSignException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToExecuteException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	ob.setExecutor(hermes);

	try {
		ob.doBureaucracy("aaaaaaaaa", "Bender");
	}
	catch (OfficeBlock::NoInternException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecutorException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Intern::UknownFormException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToSignException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToExecuteException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		ob.doBureaucracy("presidental pardon", "Bender");
	}
	catch (OfficeBlock::NoInternException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecutorException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Intern::UknownFormException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToSignException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToExecuteException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat  bill = Bureaucrat("Bill Gates", 1);
	Bureaucrat  mike = Bureaucrat("Mike Tyson", 1);

	ob.setSigner(bill);

	try {
		ob.doBureaucracy("presidental pardon", "Bender");
	}
	catch (OfficeBlock::NoInternException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecutorException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Intern::UknownFormException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToSignException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToExecuteException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	ob.setExecutor(mike);

	try {
		ob.doBureaucracy("presidental pardon", "Bender");
	}
	catch (OfficeBlock::NoInternException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecutorException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Intern::UknownFormException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToSignException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::GradeTooLowToExecuteException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
