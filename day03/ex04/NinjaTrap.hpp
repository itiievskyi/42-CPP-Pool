/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:01:32 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/02 16:01:33 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
# define NINJATRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap {

public:

	NinjaTrap(std::string name);
	NinjaTrap(void);
	NinjaTrap(NinjaTrap const &src);
	NinjaTrap(int);
	~NinjaTrap(void);

	NinjaTrap &operator=(NinjaTrap const &src);

	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);

	void 	ninjaShoebox(NinjaTrap &target);
	void 	ninjaShoebox(ClapTrap &target);
	void 	ninjaShoebox(FragTrap &target);
	void 	ninjaShoebox(ScavTrap &target);

private:

};

#endif
