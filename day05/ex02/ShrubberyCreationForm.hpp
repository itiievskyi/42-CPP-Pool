/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:54:15 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 10:54:16 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREAIONFORM_H
# define SHRUBBERYCREAIONFORM_H

# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:

	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	virtual ~ShrubberyCreationForm(void);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

	virtual void execute(Bureaucrat const &executor) const;

private:

};

#endif
