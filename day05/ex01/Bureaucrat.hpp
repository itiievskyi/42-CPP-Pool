/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:47:57 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/08 12:47:58 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREACRAT_H
# define BUREACRAT_H

# include <iostream>

class Form;

class Bureaucrat {

public:

	Bureaucrat(const std::string name, int grade);
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);
	Bureaucrat &operator=(Bureaucrat const &src);

	void upGrade(void);
	void downGrade(void);
	void signForm(Form &form);

	std::string getName(void) const;
	int getGrade(void) const;

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
	int					_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif
