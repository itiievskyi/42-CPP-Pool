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

void Good::attack() {}