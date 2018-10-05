/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:40:17 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:40:18 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include "Enemy.hpp"
# include "AWeapon.hpp"

class Character {

public:

	Character(void);
	Character(std::string const &name);
	Character(Character const &src);
	Character &operator=(Character const &src);
	~Character(void);

	void recoverAP(void);
	void equip(AWeapon *);
	void attack(Enemy *);
	std::string getName(void) const;
	int getAP(void) const;
	int getMaxAP(void) const;
	AWeapon *getWeapon(void) const;
	bool getEquipped(void) const;

private:

	int	_ap;
	int	_maxAp;
	std::string		_name;
	AWeapon			*_weapon;
	bool			_equipped;

};

std::ostream &operator<<(std::ostream &o, Character const &src);

#endif
