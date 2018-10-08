/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:51:00 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/08 16:51:01 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Form {

public:

	Form(const std::string name, int signGrade, int execGrade);
	Form(void);
	Form(Form const &src);
	~Form(void);
	Form &operator=(Form const &src);

	void beSigned(Bureaucrat &signer);

	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	bool getIsSigned(void) const;

	class GradeTooLowException : public std::exception {

	public:
		GradeTooLowException(void);
		GradeTooLowException(const GradeTooLowException &src);
		virtual ~GradeTooLowException(void) throw();
		GradeTooLowException  &operator=(const GradeTooLowException &src);
		virtual const char    *what() const throw();
	};

	class GradeTooHighException : public std::exception {

	public:
		GradeTooHighException(void);
		GradeTooHighException(const GradeTooHighException &src);
		virtual ~GradeTooHighException(void) throw();
		GradeTooHighException &operator= (const GradeTooHighException &src);
		virtual const char    *what() const throw();
	};

private:

	std::string			_name;
	int					_signGrade;
	int					_execGrade;
	bool				_isSigned;
};

std::ostream &operator<<(std::ostream &o, Form const &src);

#endif
