/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:50:27 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/06 08:50:28 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define COLOR_GREY 8
# define HELP_LINES 30
# define HELP_COLS 103
# define NUM_OF_ENEMIES 42
# define HEIGHT 66
# define WIDTH 197

# include <iostream>
# include "SpaceShip.hpp"
# include "Enemy.hpp"
# include "Good.hpp"
# include "Bullet.hpp"

class Game {

public:

	Game(void);
	Game(Game const &src);
	Game &operator=(Game const &src);
	~Game(void);

/*
**	Ncurses functions
*/
	void init_colors(void) const;
	void print_template(void) const;
	void check_button(void);
	void updatePlayers(void);
	void print_map(void);
	static void sighandler(int signum);

/*
**	Game functions
*/

	void manage_bullets();
	void pushBullet(Bullet *);
	void findShip(int y, int x);
	void findBullet(int y, int x);

/*
**	Getters & Setters
*/

	int getResult(void) const;
	void setResult(int);
	int getScore(void) const;
	void setScore(int);
	int getCycle(void) const;
	void setCycle(int);

private:

	typedef struct		s_bullet {
		Bullet			*bullet;
		struct s_bullet	*next;
	}					t_bullet;

	int			_result;
	int			_score;
	int			_pause;
	int			_liveEnemies;
	int			_respawnDelay;
	int			_cycle;
	char		_map[HEIGHT][WIDTH];
	Enemy		*_enemies[NUM_OF_ENEMIES];
	Good		_hero;
	t_bullet	*_bulletList;

};

#endif
