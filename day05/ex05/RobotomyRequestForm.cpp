/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:54:27 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 10:54:28 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
Form("Robotomization request", target, 72, 45) {

	return;
}

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomization request", "Uknown person", 72, 45) {

	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
Form("Robotomization request", src.getTarget(), 72, 45) {

	*this = src;

	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {

	static_cast <void>(src);

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

	return;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {

	static int count = 0;

	Form::execute(executor);

	std::cout << "* bzhh... trr.... zzzzzzztr... *" << std::endl;

	if (count % 2 == 0) {
		std::cout << this->getTarget() << " has been successfully robotomized."
		<< std::endl;
	} else {
		std::cout << this->getTarget() << "'s robotomization failed."
		<< std::endl;
	}

	++count;
}
