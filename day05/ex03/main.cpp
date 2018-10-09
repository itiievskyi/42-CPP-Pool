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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

	Intern  someRandomIntern;

	Form*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	Form*   form;
	form = someRandomIntern.makeForm("another form", "Kitty");

	form = someRandomIntern.makeForm("presidental pardon", "Bender");

	Bureaucrat teo = Bureaucrat("Teo", 1);

	std::cout << *form;

	teo.signForm(*form);
	teo.executeForm(*form);

	return 0;
}
