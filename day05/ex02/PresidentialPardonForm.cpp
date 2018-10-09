/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:54:51 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 10:54:52 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
Form("Presidential Pardon", target, 25, 5) {

	return;
}

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon", "Uknown person", 25, 5) {

	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
Form("Presidential Pardon", src.getTarget(), 25, 5) {

	*this = src;

	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {

	static_cast <void>(src);

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

	return;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {

	Form::execute(executor);

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox."
	<< std::endl;
}
