/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 08:52:14 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/02 08:52:19 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>

class FragTrap {

public:

	FragTrap(std::string name);
	~FragTrap(void);

	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const &target);

private:

	std::string	_name;

	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;
	unsigned int	_level;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReduction;

	unsigned int	_funzerkerDamage;
	unsigned int	_blightbotDamage;
	unsigned int	_miniontrapDamage;
	unsigned int	_clapInTheBoxDamage;
	unsigned int	_laserInfernoDamage;

	unsigned int	_accumulatedDamage;

	void			checkLevel(void);

	void funzerker(std::string const & target);
	void blightbot(std::string const & target);
	void miniontrap(std::string const & target);
	void clapInTheBox(std::string const & target);
	void laserInferno(std::string const & target);

};

#endif
