
#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>

class FragTrap {

public:

	FragTrap(std::string name);
	~FragTrap(void);



private:

	std::string	_name;
	int			_hitPoints;
	int			_maxHitPoints;
	int			_energyPoints;
	int			_maxEnergyPoints;
	int			_level;
	int			_meleeAttackDamage;
	int			_RangedAttackDamage;
	int			_meleeAttackDamage;
	int			_armorDamageReduction;

};


#endif
