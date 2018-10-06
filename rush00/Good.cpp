/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Good.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:13:40 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/06 17:13:41 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Good.hpp"

Good::Good() : SpaceShip() {}

Good::Good(int x, int y) : SpaceShip(x, y) {}

Good::Good(Good const &g) {
	*this = g;
}

Good::~Good() {}

Good & Good::operator=(Good const &g) {
	if (this != &g)
	{
		this->x = g.getX();
		this->y = g.getY();
	}
	return *this;
}

void Good::attack() {

	this->_bullet = new Bullet(false, this->y + 1, this->x);
	this->_activeAttack = true;

	return;
}
