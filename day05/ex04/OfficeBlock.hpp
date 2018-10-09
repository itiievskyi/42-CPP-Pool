/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:51:24 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 16:51:27 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_H
# define OFFICEBLOCK_H

# include <iostream>
# include "Form.hpp"
# include "Intern.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class OfficeBlock {

public:

	OfficeBlock(void);
	OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executer);
	OfficeBlock(OfficeBlock const &src);
	~OfficeBlock(void);
	OfficeBlock &operator=(OfficeBlock const &src);

	class NoInternException : public std::exception {

	public:
		NoInternException(void);
		NoInternException(const NoInternException &src);
		virtual ~NoInternException(void) throw();
		NoInternException  &operator=(const NoInternException &src);
		virtual const char    *what() const throw();
	};

	class NoSignerException : public std::exception {

	public:
		NoSignerException(void);
		NoSignerException(const NoSignerException &src);
		virtual ~NoSignerException(void) throw();
		NoSignerException  &operator=(const NoSignerException &src);
		virtual const char    *what() const throw();
	};

	class NoExecutorException : public std::exception {

	public:
		NoExecutorException(void);
		NoExecutorException(const NoExecutorException &src);
		virtual ~NoExecutorException(void) throw();
		NoExecutorException  &operator=(const NoExecutorException &src);
		virtual const char    *what() const throw();
	};

	class GradeTooLowToSignException : public std::exception {

	public:
		GradeTooLowToSignException(void);
		GradeTooLowToSignException(const GradeTooLowToSignException &src);
		virtual ~GradeTooLowToSignException(void) throw();
		GradeTooLowToSignException  &operator=(const GradeTooLowToSignException &src);
		virtual const char    *what() const throw();
	};

	class GradeTooLowToExecuteException : public std::exception {

	public:
		GradeTooLowToExecuteException(void);
		GradeTooLowToExecuteException(const GradeTooLowToExecuteException &src);
		virtual ~GradeTooLowToExecuteException(void) throw();
		GradeTooLowToExecuteException  &operator=(const GradeTooLowToExecuteException &src);
		virtual const char    *what() const throw();
	};

	void doBureaucracy(std::string type, std::string target);

	void setIntern(Intern &intern);
	void setSigner(Bureaucrat &signer);
	void setExecutor(Bureaucrat &executer);

private:

	Intern		*_intern;
	Bureaucrat	*_signer;
	Bureaucrat	*_executer;

};

#endif
