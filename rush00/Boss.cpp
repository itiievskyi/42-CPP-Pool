#include "Boss.hpp"

Boss::Boss() : SpaceShip() {}

Boss::Boss(int x, int y) : SpaceShip(x, y) {}

Boss::Boss(Boss const &b) {
	*this = b;
}

Boss::~Boss() {}

Boss & Boss::operator=(Boss const &b) {
	if (this != &b)
	{
		this->x = b.getX();
		this->y = b.getY();
	}
	return *this;
}

void Boss::attack() {}