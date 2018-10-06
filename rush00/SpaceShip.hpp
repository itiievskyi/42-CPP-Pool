#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <iostream>

class SpaceShip
{
protected:
	int x;
	int y;
public:
	SpaceShip();
	SpaceShip(int x, int y);
	SpaceShip(SpaceShip const &s);
	~SpaceShip();

	SpaceShip & operator=(SpaceShip const &s);

	int  getX() const;
	int  getY() const;
	void setX(int x);
	void setY(int y);

	virtual void attack() = 0;
};

#endif