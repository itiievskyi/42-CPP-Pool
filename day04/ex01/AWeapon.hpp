/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:37:34 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:37:37 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_H
# define AWEAPON_H

# include <iostream>

class AWeapon {

public:

	AWeapon(void);
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const &src);
	AWeapon &operator=(AWeapon const &src);
	virtual ~AWeapon(void);

	std::string getName(void) const;
	int getAPCost(void) const;
	int getDamage(void) const;
	virtual void attack(void) const = 0;

private:

	std::string	_name;
	int			_apcost;
	int			_damage;

};

#endif
