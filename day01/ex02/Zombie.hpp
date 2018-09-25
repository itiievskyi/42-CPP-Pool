/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:38:44 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 09:38:45 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class	Zombie {

public:

	Zombie(std::string name, std::string type);
	~Zombie(void);

	void		announce(void) const;

	std::string	getName(void) const;
	std::string	getType(void) const;
	std::string	getPhrase(void) const;

	void		setPhrase(std::string phrase);

private:

	std::string	_name;
	std::string	_type;
	std::string	_phrase;

};

#endif
