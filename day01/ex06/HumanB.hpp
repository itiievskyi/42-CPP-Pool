/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:52:52 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/26 10:52:53 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include <iostream>
# include "Weapon.hpp"

class	HumanB {

public:

	HumanB(std::string name);
	~HumanB(void);

	void	attack(void) const;
	void	setWeapon(Weapon &weapon);

private:

	std::string _name;
	Weapon		*_weapon;

};

#endif
