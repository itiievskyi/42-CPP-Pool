/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:45:16 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 17:45:17 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <iostream>

void Human::meleeAttack(std::string const & target)
{
	std::cout << "Your warrior use some judo tricks against " <<
	target << "." << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << "Your warrior tries to hit " << target
	<< " using Kar '98." << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "Your warrior shouts as loudly as he can to scare " <<
	target << "." << std::endl;
}

void Human::action(std::string const &action_name, std::string const &target) {

	std::string f[3] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};

	void (Human::*funcs[3])(std::string const &) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	std::string *pos = std::find(std::begin(f), std::end(f), action_name);
	int num = std::distance(f, pos);

	if (num < 0 || num > 2) {
		std::cout << "Your warrior wants to do something against " <<
		target << " but doesn't know what to do." << std::endl;
		return;
	}

	(this->*funcs[num])(target);

}
