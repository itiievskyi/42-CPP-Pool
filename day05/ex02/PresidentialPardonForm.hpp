/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:54:46 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 10:54:47 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_H
# define PRESIDENTALPARDONFORM_H

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form {

public:

	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	virtual ~PresidentialPardonForm(void);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

	virtual void execute(Bureaucrat const &executor) const;

private:

};

#endif
