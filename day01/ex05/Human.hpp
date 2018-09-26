/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:45:21 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 17:45:22 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
# define HUMAN_H

# include <iostream>
# include "Brain.hpp"

class	Human {

public:

	Human();
	~Human(void);
	Brain &getBrain(void);
	std::string identify(void) const;
	void setName(std::string name);
	std::string getName(void) const;

private:

	Brain	*_brain;
	std::string _name;

};

#endif
