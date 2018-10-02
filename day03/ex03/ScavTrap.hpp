/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 12:49:36 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/02 12:49:38 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap(std::string name);
	ScavTrap(void);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	ScavTrap &operator=(ScavTrap const &src);

	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);

	void	challengeNewcomer(std::string const &target);

private:

};

#endif
