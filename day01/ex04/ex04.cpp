/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:23:16 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 17:23:17 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void) {

	std::string		justBrain = "HI THIS IS BRAIN";

	std::string		*ptrBrain = &justBrain;
	std::string		&refBrain = justBrain;

	std::cout << *ptrBrain << std::endl;
	std::cout << refBrain << std::endl;
	return 0;
}
