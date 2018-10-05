/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:36:54 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:37:07 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"

int main() {

/*
**	Standard tests
*/

	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;

	vlc->push(bob);
	vlc->push(jim);

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;

/*
**	Additional tests
*/

	std::cout << "\nADDITIONAL TESTS\n" << std::endl;

	ISquad* squad = new Squad;

	ISpaceMarine* a = new TacticalMarine;
	ISpaceMarine* b = new AssaultTerminator;

	squad->push(a);
	std::cout << "squad size = " << squad->getCount() << std::endl;
	squad->push(b);
	std::cout << "squad size = " << squad->getCount() << std::endl;
	squad->push(a);
	std::cout << "squad size = " << squad->getCount() << std::endl;

	std::cout << "unit 0 says: ";
	squad->getUnit(0) ? squad->getUnit(0)->battleCry() : (void)squad;
	std::cout << "unit 1 says: ";
	squad->getUnit(1) ? squad->getUnit(1)->battleCry() : (void)squad;
	std::cout << "unit 2 says: ";
	squad->getUnit(2) ? squad->getUnit(2)->battleCry() : (void)squad;
	std::cout << std::endl << std::endl;

	ISpaceMarine* c = b;

	squad->push(c);
	std::cout << "squad size = " << squad->getCount() << std::endl;

	ISpaceMarine* d = b->clone();
	squad->push(d);
	std::cout << "squad size = " << squad->getCount() << std::endl;

	Squad* original = new Squad;
	original->push(a);
	original->push(b);

	std::cout << "original size = " << original->getCount() << std::endl;

	Squad* clone = original;

	std::cout << "clone size = " << clone->getCount() << std::endl;

	Squad* temp = new Squad;
	temp->push(d);

	std::cout << "temp size = " << temp->getCount() << std::endl;
	temp->push(d);
	temp->push(d);
	temp->push(a);
	temp->push(b);
	temp->push(c);

	*clone = *temp;
	std::cout << "clone size = " << clone->getCount() << std::endl;

	std::cout << "Temp:" << std::endl;

	temp->getUnit(0) ? temp->getUnit(0)->battleCry() : (void)temp;
	temp->getUnit(1) ? temp->getUnit(1)->battleCry() : (void)temp;
	temp->getUnit(2) ? temp->getUnit(2)->battleCry() : (void)temp;

	std::cout << "Clone:" << std::endl;

	clone->getUnit(0) ? clone->getUnit(0)->battleCry() : (void)clone;
	clone->getUnit(1) ? clone->getUnit(1)->battleCry() : (void)clone;
	clone->getUnit(2) ? clone->getUnit(2)->battleCry() : (void)clone;

	delete clone;

	std::cout << "Temp:" << std::endl;
	temp->getUnit(0) ? temp->getUnit(0)->battleCry() : (void)temp;
	temp->getUnit(1) ? temp->getUnit(1)->battleCry() : (void)temp;
	temp->getUnit(2) ? temp->getUnit(2)->battleCry() : (void)temp;

	delete temp;

	return 0;
}
