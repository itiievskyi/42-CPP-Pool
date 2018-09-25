/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:39:17 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 09:39:18 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

int		main(void) {

	ZombieHorde		stackHorde = ZombieHorde(3);
	ZombieHorde		*heapHorde = new ZombieHorde(5);
	ZombieHorde		nullHorde = ZombieHorde(0);

	stackHorde.announce();
	heapHorde->announce();

	delete heapHorde;

	return 0;
}
