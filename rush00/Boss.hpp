#ifndef BOSS_HPP
#define BOSS_HPP

#include "SpaceShip.hpp"

class Boss : public SpaceShip
{
public:
	Boss();
	Boss(int x, int y);
	Boss(Boss const &b);
	~Boss();

	Boss & operator=(Boss const &b);

	void attack();
};

#endif