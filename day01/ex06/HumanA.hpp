/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:52:44 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/26 10:52:45 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include "Weapon.hpp"

class	HumanA {

public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	attack(void) const;

private:

	std::string _name;
	Weapon		*_weapon;

};

#endif
