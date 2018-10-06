#include "SpaceShip.hpp"

SpaceShip::SpaceShip() {}

SpaceShip::SpaceShip(int x, int y) : x(x), y(y) {}

SpaceShip::SpaceShip(SpaceShip const &s) {
	*this = s;
}

SpaceShip::~SpaceShip() {}

SpaceShip & SpaceShip::operator=(SpaceShip const &s) {
	if (this != &s)
	{
		this->x = s.getX();
		this->y = s.getY();
	}
	return *this;
}

int  SpaceShip::getX() const {
	return x;
}

int  SpaceShip::getY() const {
	return y;
}

void SpaceShip::setX(int x) {
	this->x = x;
}

void SpaceShip::setY(int y) {
	this->y = y;
}
