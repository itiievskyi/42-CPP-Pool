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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

	Bureaucrat *bob = new Bureaucrat("Bob", 1);
	Bureaucrat *jim = new Bureaucrat("Jim", 42);
	Bureaucrat *mike = new Bureaucrat("Mike", 100);

	std::cout << *bob << *jim << *mike;

	PresidentialPardonForm *president = new PresidentialPardonForm("Killer");
	RobotomyRequestForm *robot_one = new RobotomyRequestForm("Human");
	ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("home");

	std::cout << *president << *robot_one; //<< *shrubbery;

	RobotomyRequestForm *robot_two = robot_one;
	RobotomyRequestForm *robot_three = new RobotomyRequestForm(*robot_one);

	std::cout << *robot_two << *robot_three;

	try {
		mike->executeForm(*president);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		mike->signForm(*president);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bob->signForm(*president);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		jim->executeForm(*president);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bob->executeForm(*president);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bob->executeForm(*robot_one);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bob->signForm(*robot_one);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bob->executeForm(*robot_one);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bob->executeForm(*robot_two);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bob->signForm(*shrubbery);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bob->executeForm(*shrubbery);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bob->executeForm(*shrubbery);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
