/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:44:51 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/06 08:44:52 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Good.hpp"
#include "Bullet.hpp"
#include "Boss.hpp"
#include <ncurses.h>
#include <ctime>
#include <unistd.h>
#include <cstdio>

int main() {

	std::srand(std::time(nullptr));

	setlocale(LC_ALL, "en_US.UTF-8");

	Game *game = new Game;

	initscr();
	start_color();
	curs_set(0);
	cbreak();
	noecho();
	game->init_colors();
	game->print_template();

	while (!game->getResult()) {
		nodelay(stdscr, TRUE);
		game->manage_bullets();
		game->updatePlayers();
		game->check_button();
		game->print_map();
		refresh();
		usleep(15000);
	}
	refresh();
	game->finish_game();
	refresh();
	endwin();
	std::system("clear");

	// std::system("leaks ft_retro > leaks.log");

	return 0;
}
