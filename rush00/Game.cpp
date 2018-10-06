/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:50:34 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/06 08:50:36 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <ncurses.h>
#include <panel.h>

Game::Game(void) {

	this->_result = 0;
	this->_score = 0;
	this->_pause = 0;

	return;
}

Game::Game(Game const &src) {

	*this = src;

	return;
}

Game &Game::operator=(Game const &src) {

	if (this != &src) {
		this->_result = src.getResult();
	}

	return *this;
}

Game::~Game(void) {

	return;
}

void Game::init_colors(void) const {

	init_pair(1, COLOR_GREY, COLOR_GREY);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_YELLOW, COLOR_BLACK);

	return;
}

void Game::print_template(void) const {

	int x = 0;
	int y = 0;

	attron(COLOR_PAIR(1) | A_BOLD);
	while (x < 252)
		mvprintw(y, x++, "*");
	x = 0;
	while (x < 252)
		mvprintw(7, x++, "*");
	while (y++ < 73)
	{
		mvprintw(y, 0, "*");
		mvprintw(y, 198, "*");
		mvprintw(y, 251, "*");
		if ((y == 50 || y == 57 || y == 34) && (x = 198))
			while (x < 252)
				mvprintw(y, x++, "*");
	}
	x = 0;
	while (x < 252)
		mvprintw(y, x++, "*");
	init_colors();
	attron(COLOR_PAIR(2));
	mvprintw(1, 15, "%S",
	L" ██╗  ██╗██████╗     ██╗███╗   ██╗██╗   ██╗ █████╗ ██████╗ ███████╗██████╗ ███████╗ ");
	mvprintw(2, 15, "%S",
	L" ██║  ██║╚════██╗    ██║████╗  ██║██║   ██║██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔════╝");
	mvprintw(3, 15, "%S",
	L" ███████║ █████╔╝    ██║██╔██╗ ██║██║   ██║███████║██║  ██║█████╗  ██████╔╝███████╗");
	mvprintw(4, 15, "%S",
	L" ╚════██║██╔═══╝     ██║██║╚██╗██║╚██╗ ██╔╝██╔══██║██║  ██║██╔══╝  ██╔══██╗╚════██║");
	mvprintw(5, 15, "%S",
	L"      ██║███████╗    ██║██║ ╚████║ ╚████╔╝ ██║  ██║██████╔╝███████╗██║  ██║███████║");
	mvprintw(6, 15, "%S",
	L"      ╚═╝╚══════╝    ╚═╝╚═╝  ╚═══╝  ╚═══╝  ╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝");
	attroff(COLOR_PAIR(1) | A_BOLD);
	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(3, 111, "%s", "┌┐ ┬ ┬");
	mvprintw(4, 111, "%s", "├┴┐└┬┘");
	mvprintw(5, 111, "%s", "└─┘ ┴ ");
	attron(COLOR_PAIR(4) | A_BOLD);
	mvaddstr(3, 129, "┌─┐┌┬┐┬ ┬┌─┐┌─┐┬  ┬ ┬┬┌─     ┬     ┬┌┬┐┬┬┌─┐┬  ┬┌─┐┬┌─");
	mvaddstr(4, 129, "├┤  │ │ ││ ┬│ ││  │ │├┴┐    ┌┼─    │ │ ││├┤ └┐┌┘└─┐├┴┐");
	mvaddstr(5, 129, "└─┘ ┴ └─┘└─┘└─┘┴─┘└─┘┴ ┴    └┘     ┴ ┴ ┴┴└─┘ └┘ └─┘┴ ┴");
	attron(COLOR_PAIR(5) | A_BOLD);
	mvaddstr(1, 207, " _     _____ ____ _____ _   _ ____  ");
	mvaddstr(2, 207, "| |   | ____/ ___| ____| \\ | |  _ \\ ");
	mvaddstr(3, 207, "| |   |  _|| |  _|  _| |  \\| | | | |");
	mvaddstr(4, 207, "| |___| |__| |_| | |___| |\\  | |_| |");
	mvaddstr(5, 207, "|_____|_____\\____|_____|_| \\_|____/ ");
	mvaddstr(1 + 50, 207 + 5, " _   _ _____ _     ____  ");
	mvaddstr(2 + 50, 207 + 5, "| | | | ____| |   |  _ \\ ");
	mvaddstr(3 + 50, 207 + 5, "| |_| |  _| | |   | |_) |");
	mvaddstr(4 + 50, 207 + 5, "|  _  | |___| |___|  __/ ");
	mvaddstr(5 + 50, 207 + 5, "|_| |_|_____|_____|_|    ");
	mvaddstr(69, 202, "Press CTRL+C to exit at any time");
	attroff(COLOR_PAIR(5) | A_BOLD);

	mvaddstr(71, 202, "The project is prepared for 42School's project");
	mvaddstr(72, 202, "CPP-POOL / Rush00 in 2018. All rights reserved");
//	mvprintw(37 - 1, 202, "The current game speed modifier:  0");
	attroff(COLOR_PAIR(5) | A_BOLD);

	return;
}

void Game::sighandler(int signum) {

	int				ch;
	WINDOW			*win;

	PANEL * quit_panel;
	raw();

	int		startx;
	int		starty;
	int		height;
	int		width;
	float	center;

	win = newwin(HELP_LINES, HELP_COLS, 64 / 2 - 15 + 8, 198 / 2 - 51);
	getbegyx(win, starty, startx);
	getmaxyx(win, height, width);
	box(win, 0, 0);
	mvwaddch(win, 2, 0, ACS_LTEE);
	mvwhline(win, 2, 1, ACS_HLINE, width - 2);
	mvwaddch(win, 2, width - 1, ACS_RTEE);
	center = width / 2;
	wattron(win, COLOR_PAIR(6) | A_BOLD);
	mvwaddstr(win, 1, center - 14, "Are you sure you want to quit???");
	wattron(win, COLOR_PAIR(7) | A_BOLD);
	mvwaddstr(win, height - 5, center - 22,
		"Press 'n' to resume the game or 'y' to quit");
	wattron(win, COLOR_PAIR(5) | A_BOLD);
	mvwaddstr(win, 4 + 1, 5, "You're going to quit the game!");
	mvwaddstr(win, 6 + 1, 5, "Is that a problem?");
	wattron(win, COLOR_PAIR(7) | A_BOLD);
	mvwaddstr(win, 8 + 1, 5, "YES!");
	wattron(win, COLOR_PAIR(5) | A_BOLD);
	mvwaddstr(win, 10 + 1, 5, "We did our best to make this fucking VM run!");
	mvwaddstr(win, 12 + 1, 5, "And now what?! You just quit!");
	mvwaddstr(win, 16 + 1, 5, "Ok, let's talk like adults.");
	mvwaddstr(win, 18 + 1, 5, "If your have balls, just press 'n' and watch.");
	mvwaddstr(win, 20 + 1, 5,
		"Otherwise, you may press 'y' and run from here as far as you can.");

	quit_panel = new_panel(win);
	update_panels();
	doupdate();
	while ((ch = getch()))
	{
		if (ch == 'y' || ch == 'Y') {
			endwin();
			system("clear");
			exit(signum);
		}

		if (ch == 'n' || ch == 'N')
			break ;
		update_panels();
		doupdate();
		ch = '\0';
	}
	hide_panel(quit_panel);
	free(quit_panel);
	cbreak();
}



void Game::check_pause(void) {


	return;
}

int Game::getResult(void) const {

	return this->_result;
}

void Game::setResult(int result) {

	this->_result = result;

	return;
}

int Game::getScore(void) const {

	return this->_score;
}

void Game::setScore(int score) {

	if (score >= 0) {
		this->_score += score;
	}

	return;
}
