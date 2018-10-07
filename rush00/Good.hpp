#ifndef GOOD_HPP
# define GOOD_HPP

# include "SpaceShip.hpp"
# include "Bullet.hpp"

class Good : public SpaceShip {

public:
	Good();
	Good(int x, int y);
	Good(Good const &g);
	~Good();

	Good & operator=(Good const &g);

	void attack();

};

#endif
