#include "SpaceShip.hpp"
#include "Bullet.hpp"

SpaceShip::SpaceShip() {}

SpaceShip::SpaceShip(int x, int y) : x(x), y(y) {

	this->_bullet = nullptr;
	this->_bulletM = nullptr;
	this->_bulletB = nullptr;
	this->_activeAttack = false;
	this->_status = 0;

}

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

bool  SpaceShip::getActiveAttack() const {

	return this->_activeAttack;
}

Bullet *SpaceShip::getBullet() const {

	return this->_bullet;
}

Bullet *SpaceShip::getBulletM() const {

	return this->_bulletM;
}

Bullet *SpaceShip::getBulletB() const {

	return this->_bulletB;
}

void SpaceShip::setActiveAttack(bool act) {

	this->_activeAttack = act;

	return;
}
void  SpaceShip::setBullet(Bullet* bullet) {

	this->_bullet = bullet;

	return;
}

int  SpaceShip::getStatus() const {

	return this->_status;
}
void SpaceShip::setStatus(int status) {

	this->_status = status;

	return;
}

int  SpaceShip::getHP() const {

	return this->_hp;
}

void SpaceShip::takeDamage(int damage) {

	if (this->_hp > 0) {
		this->_hp -= damage;
	}

	if (this->_hp < 0) {
		this->_hp = 0;
	}

	if (this->_hp == 0) {
		this->_status = -1;
	}

	return;
}

void  SpaceShip::setHP(int hp) {

	this->_hp = hp;

	return;
}

void  SpaceShip::setInjure(int inj) {

	this->_injure = inj;

	return;
}


int  SpaceShip::getInjure() const {

	return this->_injure;
}
