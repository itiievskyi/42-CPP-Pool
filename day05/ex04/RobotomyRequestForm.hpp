/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:54:31 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 10:54:32 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public Form {

public:

	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	virtual ~RobotomyRequestForm(void);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

	virtual void execute(Bureaucrat const &executor) const;

private:

};

#endif
