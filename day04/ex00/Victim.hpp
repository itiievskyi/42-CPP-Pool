/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:51:05 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:51:07 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_H
# define VICTIM_H

# include <iostream>

class Victim {

public:

	Victim(std::string name);
	Victim(void);
	Victim(Victim const &src);
	virtual ~Victim(void);
	Victim &operator=(Victim const &src);

	std::string getName(void) const;

	virtual void getPolymorphed(void) const;

protected:

	std::string _name;

};

std::ostream &operator<<(std::ostream &o, Victim const &src);

#endif
