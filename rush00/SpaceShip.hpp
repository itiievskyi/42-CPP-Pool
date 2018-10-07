#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <iostream>
#include "Bullet.hpp"

class SpaceShip {

protected:
	int x;
	int y;
	Bullet *_bullet;
	Bullet	*_bulletM;
	Bullet	*_bulletB;
	int _activeAttack;
	int _status;
	int _hp;
	int _injure;

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
	Bullet *getBulletM() const;
	Bullet *getBulletB() const;
	void setX(int x);
	void setY(int y);
	void setActiveAttack(bool act);
	void setBullet(Bullet*);
	void setStatus(int status);
	int  getHP() const;
	void setHP(int);
	int  getInjure() const;
	void setInjure(int);
	void takeDamage(int damage);

	virtual void attack() = 0;
};

#endif
