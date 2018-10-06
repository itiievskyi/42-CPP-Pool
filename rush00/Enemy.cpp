#include "Enemy.hpp"

Enemy::Enemy() : SpaceShip() {}

Enemy::Enemy(int x, int y) : SpaceShip(x, y) {}

Enemy::Enemy(Enemy const &e) {
	*this = e;
}

Enemy::~Enemy() {}

Enemy & Enemy::operator=(Enemy const &e) {
	if (this != &e)
	{
		this->x = e.getX();
		this->y = e.getY();
	}
	return *this;
}

void Enemy::attack() {}