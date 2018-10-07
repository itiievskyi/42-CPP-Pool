#ifndef BOSS_HPP
# define BOSS_HPP

# include "SpaceShip.hpp"
# include "Bullet.hpp"

class Boss : public SpaceShip {

public:
	Boss();
	Boss(int x, int y);
	Boss(Boss const &b);
	~Boss();

	Boss & operator=(Boss const &b);

	void move(char);
	void attack();
	char getBodyPiece(int x, int y) const;

private:

	char	_body[5][2];
};

#endif
