/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:45:31 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 17:45:32 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <iostream>

int		main(void) {

	Human bob;

	bob.action("meleeAttack", "Osama");
	bob.action("rangedAttack", "Saddam");
	bob.action("intimidatingShout", "Hitler");

	bob.action("bladeAttack", "Joker");

	return 0;
}
