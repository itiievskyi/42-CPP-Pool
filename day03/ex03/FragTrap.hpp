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

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap(std::string name);
	FragTrap(void);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	FragTrap &operator=(FragTrap const &src);

	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
	void	vaulthunter_dot_exe(std::string const &target);

	unsigned int getFunzerkerDamage(void);
	unsigned int getBlightbotDamage(void);
	unsigned int getMiniontrapDamage(void);
	unsigned int getClapInTheBoxDamage(void);
	unsigned int getLaserInfernoDamage(void);

private:

	unsigned int	_funzerkerDamage;
	unsigned int	_blightbotDamage;
	unsigned int	_miniontrapDamage;
	unsigned int	_clapInTheBoxDamage;
	unsigned int	_laserInfernoDamage;

	void funzerker(std::string const & target);
	void blightbot(std::string const & target);
	void miniontrap(std::string const & target);
	void clapInTheBox(std::string const & target);
	void laserInferno(std::string const & target);

};

#endif
