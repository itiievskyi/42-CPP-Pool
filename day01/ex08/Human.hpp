/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:45:21 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 17:45:22 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
# define HUMAN_H

# include <iostream>

class	Human {

private:

	void meleeAttack(std::string const &target);
	void rangedAttack(std::string const &target);
	void intimidatingShout(std::string const &target);

public:

	void action(std::string const &action_name, std::string const &target);

};

#endif
