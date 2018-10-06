#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "SpaceShip.hpp"

class Enemy : public SpaceShip
{
public:
	Enemy();
	Enemy(int x, int y);
	Enemy(Enemy const &e);
	~Enemy();

	Enemy & operator=(Enemy const &e);

	void attack();
};

#endif