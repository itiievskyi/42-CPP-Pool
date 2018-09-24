/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:41:17 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/24 16:41:19 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

static void	ponyOnTheHeap(void) {

	Pony*	bob = new Pony("Bob");
	bob->introduce();
	bob->setColor("white");
	std::cout << "Hm... It's " << bob->getName() << " again and I'm became " <<
	bob->getColor() << "." << std::endl;
	delete bob;
}

static void	ponyOnTheStack(void) {

	Pony	jay = Pony("Jay");
	jay.introduce();
	jay.setHeight(130);
	std::cout << "Hm... It's " << jay.getName() << " again and I'm became " <<
	jay.getHeight() << " cm." << std::endl;
}

int 		main() {

	ponyOnTheHeap();
	std::cout << std::endl;
	ponyOnTheStack();

	return 0;
}
