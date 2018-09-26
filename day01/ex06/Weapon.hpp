/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:53:06 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/26 10:53:07 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class	Weapon {

public:

	Weapon(std::string type);
	~Weapon(void);

	const std::string &getType(void) const;
	void setType(std::string type);

private:

	std::string	_type;

};

#endif
