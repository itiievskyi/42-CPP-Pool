/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:38:48 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:38:48 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include <iostream>

class Enemy {

public:

	Enemy(void);
	Enemy(int hp, std::string const &type);
	Enemy(Enemy const &src);
	Enemy &operator=(Enemy const &src);
	virtual ~Enemy(void);

	std::string getType(void) const;
	int getHP(void) const;
	void setHP(int hp);
	virtual void takeDamage(int);

private:

	int			_hp;
	std::string _type;

};

#endif
