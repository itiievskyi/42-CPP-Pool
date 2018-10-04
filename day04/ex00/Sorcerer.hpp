/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:50:45 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:50:47 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_H
# define SORCERER_H

# include <iostream>
# include "Victim.hpp"

class Sorcerer {

public:

	Sorcerer(std::string name, std::string title);
	Sorcerer(void);
	Sorcerer(Sorcerer const &src);
	~Sorcerer(void);
	Sorcerer &operator=(Sorcerer const &src);

	std::string getName(void) const;
	std::string getTitle(void) const;

	void polymorph(Victim const &) const;

private:

	std::string _name;
	std::string _title;

};

std::ostream &operator<<(std::ostream &o, Sorcerer const &src);

#endif
