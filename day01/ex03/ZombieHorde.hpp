/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:00:00 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 16:00:01 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

# include <iostream>
# include "Zombie.hpp"

class	ZombieHorde {

public:

	ZombieHorde(int N);
	~ZombieHorde(void);

	void		announce(void) const;

private:

	int			_size;
	Zombie		*_horde;
	std::string	getRandomName(void);

};

#endif
