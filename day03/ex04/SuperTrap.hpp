/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:24:15 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/02 17:24:17 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_H
# define SUPERTRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {

public:

	SuperTrap(std::string name);
	SuperTrap(void);
	SuperTrap(SuperTrap const &src);
	~SuperTrap(void);

	SuperTrap &operator=(SuperTrap const &src);

	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);


private:

};

#endif
