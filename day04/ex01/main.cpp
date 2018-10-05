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

#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "WastelandBeast.hpp"
#include "MegaGun.hpp"

int main() {

/*
**	Standard tests
*/

	Character* zaz = new Character("zaz");

	std::cout << *zaz;

	Enemy* b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);

	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

/*
**	Additional tests
*/

	Character *pers = new Character();

	std::cout << *pers;

	Enemy* mutant = new SuperMutant();
	Enemy* beast = new WastelandBeast();

	std::cout << pers->getEquipped() << std::endl;

	pers->attack(mutant);
	pers->attack(beast);

	AWeapon* mg = new MegaGun();

	pers->equip(mg);

	std::cout << *pers;
	std::cout << "mutant hp: " << mutant->getHP() << std::endl;

	pers->attack(mutant);
	std::cout << *pers;

	std::cout << "mutant hp: " << mutant->getHP() << std::endl;

	pers->attack(mutant);
	pers->attack(mutant);
	pers->attack(mutant);


	std::cout << *pers;

	pers->attack(mutant);

	pers->recoverAP();
	std::cout << *pers;

	pers->recoverAP();
	pers->recoverAP();
	pers->recoverAP();
	pers->recoverAP();
	std::cout << *pers;

	std::cout << "beast hp: " << beast->getHP() << std::endl;

	pers->attack(beast);

	std::cout << "beast hp: " << beast->getHP() << std::endl;

	pers->attack(beast);

	return 0;
}
