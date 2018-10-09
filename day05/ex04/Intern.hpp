/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:23:50 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 15:23:51 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# define NUM_OF_FUNCS 3

# include <iostream>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {

public:

	class UknownFormException : public std::exception {

	public:
		UknownFormException(void);
		UknownFormException(const UknownFormException &src);
		virtual ~UknownFormException(void) throw();
		UknownFormException  &operator=(const UknownFormException &src);
		virtual const char    *what() const throw();
	};

	Intern(void);
	Intern(Intern const &src);
	~Intern(void);
	Intern &operator=(Intern const &src);

	Form *makeForm(std::string type, std::string target);

private:

	typedef Form* (Intern::*Func)(std::string);

	Form	*_newPresidentialPardonForm(std::string target);
	Form	*_newRobotomyRequestForm(std::string target);
	Form	*_newShrubberyCreationForm(std::string target);

	Func _funcs[NUM_OF_FUNCS];

	std::string _types[NUM_OF_FUNCS];

};

#endif
