#include "Boss.hpp"

Boss::Boss() : SpaceShip() {

	this->_body[0][0] = '<';
	this->_body[0][1] = '[';
	this->_body[1][0] = '[';
	this->_body[1][1] = '[';
	this->_body[2][0] = '<';
	this->_body[2][1] = '[';
	this->_body[3][0] = '[';
	this->_body[3][1] = '[';
	this->_body[4][0] = '<';
	this->_body[4][1] = '[';

	this->_hp = 1000;
}

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

void Boss::attack() {

	this->_bullet = new Bullet('=', this->y - 1, this->x);
	this->_bulletM = new Bullet('=', this->y - 1, this->x + 2);
	this->_bulletB = new Bullet('=', this->y - 1, this->x + 4);
	this->_activeAttack = true;
}

void Boss::move(char dir) {

	if (dir == '<') {
		this->y -= 1;
	} else if (dir == '^') {
		this->x -= 1;
	} else if (dir == 'V') {
		this->x += 1;
	}
}

char Boss::getBodyPiece(int x, int y) const {

	return this->_body[x][y];
}
