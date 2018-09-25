/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:15:14 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 09:15:16 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	memoryLeak(void) {

	std::string	*panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;
	delete panthere;
}
