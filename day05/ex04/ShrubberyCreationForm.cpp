/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:53:54 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 10:53:55 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
Form("Shrubbery Creation", target, 145, 137) {

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation", "Uknown place", 145, 137) {

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
Form("Shrubbery Creation", src.getTarget(), 145, 137) {

	*this = src;

	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {

	static_cast <void>(src);

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

	return;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

	Form::execute(executor);

	std::ofstream  targetFile;

	targetFile.open(this->getTarget() + "_shrubbery", std::ofstream::out
		| std::ofstream::trunc);
	if (targetFile.fail()) {
		std::cerr << "Error: file can't be opened of created" << std::endl;
	}

	targetFile <<	"               ,@@@@@@@, " 					<< std::endl <<
					"       ,,,.   ,@@@@@@/@@,  .oo8888o. " 		<< std::endl <<
					"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o " 		<< std::endl <<
					"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' " 		<< std::endl <<
					"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' " 		<< std::endl <<
					"   %&&%/ %&%%&&@@\\ \\V /@@' `88\\8 `/88' " 		<< std::endl <<
					"   `&%\\ ` /%&'    |.|        \\ '|8' " 			<< std::endl <<
					"       |o|        | |         | | " 			<< std::endl <<
					"       |.|        | |         | | " 			<< std::endl <<
					"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" 	<< std::endl;
	targetFile.close();
	return ;
}
