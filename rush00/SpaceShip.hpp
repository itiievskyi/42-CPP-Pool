#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <iostream>
#include "Bullet.hpp"

class SpaceShip {

protected:
	int x;
	int y;
	Bullet *_bullet;
	int _activeAttack;
	int _status;

public:
	SpaceShip();
	SpaceShip(int x, int y);
	SpaceShip(SpaceShip const &s);
	~SpaceShip();

	SpaceShip & operator=(SpaceShip const &s);

	int  getX() const;
	int  getY() const;
	int  getStatus() const;
	bool  getActiveAttack() const;
	Bullet *getBullet() const;
	void setX(int x);
	void setY(int y);
	void setActiveAttack(bool act);
	void setBullet(Bullet*);
	void setStatus(int status);

	virtual void attack() = 0;
};

#endif
