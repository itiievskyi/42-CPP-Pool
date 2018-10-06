/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:09:22 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/06 16:09:23 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_H
# define BULLET_H

# include <iostream>

class Bullet {

public:

	Bullet();
	Bullet(int, int);
	Bullet(bool, int, int);
	Bullet(char, int, int);
	Bullet(Bullet const &e);
	~Bullet();
	Bullet & operator=(Bullet const &e);

	int  getX() const;
	int  getY() const;
	char  getType() const;
	bool  getBad() const;
	int  getColor() const;
	int  getDamage() const;

	void setX(int x);
	void setY(int y);
	void setType(char);
	void setBad(bool);
	void setColor(int);
	void setDamage(int);

private:

	int	_x;
	int	_y;
	char	_type;
	bool	_bad;
	int		_color;
	int		_damage;
};

#endif
