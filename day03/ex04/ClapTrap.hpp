/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 14:14:24 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/02 14:14:25 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap {

public:

	ClapTrap(void);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);

	ClapTrap &operator=(ClapTrap const &src);

	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string getName(void);
	unsigned int getMeleeAttackDamage(void);
	unsigned int getRangedAttackDamage(void);

protected:

	std::string	_name;

	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;
	unsigned int	_level;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReduction;

	unsigned int	_accumulatedDamage;
	std::string		_color;
	std::string		_type;

	void			checkLevel(void);

};

#endif
