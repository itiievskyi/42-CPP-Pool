/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:39:06 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 09:39:08 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H

# include <iostream>
# include "Zombie.hpp"

class	ZombieEvent {

public:

	ZombieEvent(void);
	~ZombieEvent(void);

	void				setZombieType(std::string type);
	std::string			getZombieType(void) const;
	Zombie*				newZombie(std::string name);
	Zombie*				randomChump(void);

private:

	std::string			_zombieType;

};

#endif
