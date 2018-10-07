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
	this->_start = std::time(0);
	this->_liveEnemies = NUM_OF_ENEMIES;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			this->_map[i][j] = ' ';
		}
	}
	for (int i = 0; i < NUM_OF_ENEMIES; i++) {
		this->_enemies[i] = new Enemy(0, 197);
	}
	int position = 0;
	for (int i = 0; i < NUM_OF_ENEMIES; i++) {
		int unique = 0;
		while (unique < NUM_OF_ENEMIES) {
			unique = 0;
			position = std::rand() % 65 + 1;
			for (int j = 0; j < NUM_OF_ENEMIES; j++) {
				if (position != this->_enemies[j]->getX()) {
					unique++;
				}
			}
		}
		this->_enemies[i]->setX(position);
	}
	this->_bulletList = nullptr;
	this->_respawnDelay = 10;
	this->_cycle = 0;
	this->_timeBonus = 10000;
	this->_hero = Good(std::rand() % 66, 1);
	this->_map[this->_hero.getX()][this->_hero.getY()] = '>';
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

void Game::findShip(int x, int y) {
x = 0;
	for (int i = 0; i < NUM_OF_ENEMIES; i++) {
		if (this->_enemies[i]->getStatus() == 1 && this->_enemies[i]->getY() == y) {
			this->_liveEnemies -= 1;
			this->_score += 100;
			this->_hero.setHP(this->_hero.getHP() + 1);
			this->_map[this->_enemies[i]->getX()][this->_enemies[i]->getY()] = ' ';
			this->_enemies[i]->setStatus(-1);
			break;
		}
	}
}
/*
void Game::findBullet(int x, int y) {

x = 0;
	t_bullet	*temp = this->_bulletList;

	while (temp && temp->next != nullptr) {
		if ( temp->next->bullet->getY() == y && temp->next->bullet->getBad() == true) {
			this->_map[temp->next->bullet->getY()][temp->next->bullet->getX()] = ' ';

			temp->next = temp->next->next;
		}
		temp = temp->next;
	}

}
*/

void Game::manage_bullets() {

	if (this->_hero.getActiveAttack() == true) {
		this->pushBullet(this->_hero.getBullet());
		this->_hero.setActiveAttack(false);
	}

	for (int i = 0; i < NUM_OF_ENEMIES; i++) {
		if (this->_enemies[i]->getActiveAttack() == true) {
			this->pushBullet(this->_enemies[i]->getBullet());
			this->_enemies[i]->setActiveAttack(false);
		}
	}

	t_bullet	*temp = this->_bulletList;

	while (temp && temp->next != nullptr) {
		if (temp->next->bullet->getBad() == false) {
			if (temp->next->bullet->getX() + 2 > WIDTH) {
				this->_map[temp->next->bullet->getY()][temp->next->bullet->getX()] = ' ';
				temp->next = temp->next->next;
			} else if (this->_map[temp->next->bullet->getY()][temp->next->bullet->getX() + 1] == '<') {
				this->_map[temp->next->bullet->getY()][temp->next->bullet->getX()] = ' ';
				this->findShip(temp->next->bullet->getY(), temp->next->bullet->getX() + 1);
				temp->next = temp->next->next;
			} else {
				this->_map[temp->next->bullet->getY()][temp->next->bullet->getX()] = ' ';
				temp->next->bullet->setX(temp->next->bullet->getX() + 1);
				this->_map[temp->next->bullet->getY()][temp->next->bullet->getX()] = temp->next->bullet->getType();
			}
		} else {
			if (this->_map[temp->next->bullet->getY()][temp->next->bullet->getX() - 1] == '>') {
				this->_map[temp->next->bullet->getY()][temp->next->bullet->getX()] = ' ';
				this->_hero.takeDamage(temp->next->bullet->getDamage());
				temp->next = temp->next->next;
			}
			if (temp->next->bullet->getX() - 2 < 0) {
				this->_map[temp->next->bullet->getY()][temp->next->bullet->getX()] = ' ';
				temp->next = temp->next->next;
			} else {
				this->_map[temp->next->bullet->getY()][temp->next->bullet->getX()] = ' ';
				temp->next->bullet->setX(temp->next->bullet->getX() - 1);
				this->_map[temp->next->bullet->getY()][temp->next->bullet->getX()] = temp->next->bullet->getType();
			}
		}
		temp = temp->next;
	}
}

void	Game::updatePlayers() {

	static int count = 0;

	if (this->_cycle % 100 == 50 && count < NUM_OF_ENEMIES) {

		this->_enemies[count]->setStatus(1);

		++count;
	}

	if (this->_cycle % 10 == 0) {
		for (int i = 0; i < NUM_OF_ENEMIES; i++) {
			if (this->_enemies[i]->getStatus() == 1) {
				if (this->_enemies[i]->getY() == 0) {
					this->_result = -1;
				}
				this->_map[this->_enemies[i]->getX()][this->_enemies[i]->getY()] = ' ';
				this->_enemies[i]->setY(this->_enemies[i]->getY() - 1);
				this->_map[this->_enemies[i]->getX()][this->_enemies[i]->getY()] = '<';
			}
		}
	}

	if (this->_cycle / 100 > 1 && this->_cycle % 100 == 1) {
		int position = 0;
		int active = 0;
		while (active != 1) {
			position = std::rand() % NUM_OF_ENEMIES;
			if (this->_enemies[position]->getStatus() == 1) {
				active = 1;
			}
		}
		this->_enemies[position]->attack();
	}

	if (this->_hero.getHP() == 0) {
		this->_result = -1;
	}

	return;
}

void Game::print_map(void) {

	static int count = 0;
	++count;
	this->_cycle = count;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			mvaddch(i + 8, j + 1, this->_map[i][j]);
		}
	}

	for (int i = 0; i < NUM_OF_ENEMIES; i++) {
		if (this->_enemies[i]->getStatus() != -1) {
			mvaddch(25 + i / 6, 214 + i % 6 + i % 6 * 3, '^');
		} else {
			mvaddch(25 + i / 6, 214 + i % 6 + i % 6 * 3, ' ');
		}
	}
	attron(COLOR_PAIR(4) | A_BOLD);
	mvprintw(9, 230, "%03d", this->_hero.getHP());
	mvprintw(11, 228, "%06d", this->_score);

	std::time_t	duration;
	std::time_t	prev_time = 0;
	std::tm		*timeinfo;
	char		timeStamp[6];
	duration = time(0) - this->_start;
	timeinfo = std::localtime(&duration);
	std::strftime(timeStamp, 5, "%M:%S", timeinfo);
	mvprintw(14, 228, "%5s", timeStamp);


	if (this->_timeBonus > 0 && this->_cycle % 2 == 1) {
		this->_timeBonus -= 1;
	}
	mvprintw(16, 234, "%05d", this->_timeBonus);

	attroff(COLOR_PAIR(4) | A_BOLD);

	prev_time = duration;
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
	init_pair(9, COLOR_GREY, COLOR_BLACK);

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
	mvaddstr(23, 213, "-=== Enemies left: ===-");
	mvaddstr(9, 217, "Player's HP: ");
	mvaddstr(11, 216, "Game score: ");
	mvaddstr(14, 217, "Game time: ");
	mvaddstr(16, 210, "Time bonus (hurry up!): ");
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
	mvaddstr(69, 202, "Press Q to see the exit menu");
	attroff(COLOR_PAIR(5) | A_BOLD);
	attroff(COLOR_PAIR(3) | A_BOLD);
	mvaddstr(61, 202, "Press P to pause the game                  ");
	mvaddstr(59, 202, "The game is running...");
	mvaddstr(71, 202, "The project is prepared for 42School's project");
	mvaddstr(72, 202, "CPP-POOL / Rush00 in 2018. All rights reserved");
	attroff(COLOR_PAIR(3) | A_BOLD);
	attron(COLOR_PAIR(8) | A_BOLD);
	mvaddstr(63, 202, "Hero, defend your borders!");
	mvaddstr(65, 202, "You can't let the invaders pass through!");
	mvaddstr(67, 202, "Be careful but brave! Empire will proud of you!");
	attroff(COLOR_PAIR(8) | A_BOLD);

	return;
}

void Game::menuHandler() {

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
	mvwaddstr(win, 1, center - 21, "Empire is in danger! Where are you going?");
	wattron(win, COLOR_PAIR(4) | A_BOLD);
	mvwaddstr(win, height - 5, center - 35, "I'm brave and I'll save you! (N)");
	wattroff(win, COLOR_PAIR(4) | A_BOLD);
	wattron(win, COLOR_PAIR(5) | A_BOLD);
	mvwaddstr(win, height - 5, center + 15, "AAhh... mommy... (Y)");
	wattroff(win, COLOR_PAIR(5) | A_BOLD);

	wattron(win, COLOR_PAIR(5));
	mvwprintw(win, 4, center - 35, " █     █░▓█████     █     █░ ██▓ ██▓     ██▓       ▓█████▄  ██▓▓█████ ");
	mvwprintw(win, 5, center - 35, "▓█░ █ ░█░▓█   ▀    ▓█░ █ ░█░▓██▒▓██▒    ▓██▒       ▒██▀ ██▌▓██▒▓█   ▀ ");
	mvwprintw(win, 6, center - 35, "▒█░ █ ░█ ▒███      ▒█░ █ ░█ ▒██▒▒██░    ▒██░       ░██   █▌▒██▒▒███   ");
	mvwprintw(win, 7, center - 35, "░█░ █ ░█ ▒▓█  ▄    ░█░ █ ░█ ░██░▒██░    ▒██░       ░▓█▄   ▌░██░▒▓█  ▄ ");
	mvwprintw(win, 8, center - 35, "░░██▒██▓ ░▒████▒   ░░██▒██▓ ░██░░██████▒░██████▒   ░▒████▓ ░██░░▒████▒");
	mvwprintw(win, 9, center - 35, "░ ▓░▒ ▒  ░░ ▒░ ░   ░ ▓░▒ ▒  ░▓  ░ ▒░▓  ░░ ▒░▓  ░    ▒▒▓  ▒ ░▓  ░░ ▒░ ░");
	mvwprintw(win, 10, center - 35, "  ▒ ░ ░   ░ ░  ░     ▒ ░ ░   ▒ ░░ ░ ▒  ░░ ░ ▒  ░    ░ ▒  ▒  ▒ ░ ░ ░  ░");

	mvwprintw(win, 4 + 9, center - 43, " █     █░ ██▓▄▄▄█████▓ ██░ ██  ▒█████   █    ██ ▄▄▄█████▓   ▓██   ██▓ ▒█████   █    ██ ");
	mvwprintw(win, 5 + 9, center - 43, "▓█░ █ ░█░▓██▒▓  ██▒ ▓▒▓██░ ██▒▒██▒  ██▒ ██  ▓██▒▓  ██▒ ▓▒    ▒██  ██▒▒██▒  ██▒ ██  ▓██▒");
	mvwprintw(win, 6 + 9, center - 43, "▒█░ █ ░█ ▒██▒▒ ▓██░ ▒░▒██▀▀██░▒██░  ██▒▓██  ▒██░▒ ▓██░ ▒░     ▒██ ██░▒██░  ██▒▓██  ▒██░");
	mvwprintw(win, 7 + 9, center - 43, "░█░ █ ░█ ░██░░ ▓██▓ ░ ░▓█ ░██ ▒██   ██░▓▓█  ░██░░ ▓██▓ ░      ░ ▐██▓░▒██   ██░▓▓█  ░██░");
	mvwprintw(win, 8 + 9, center - 43, "░░██▒██▓ ░██░  ▒██▒ ░ ░▓█▒░██▓░ ████▓▒░▒▒█████▓   ▒██▒ ░      ░ ██▒▓░░ ████▓▒░▒▒█████▓ ");
	mvwprintw(win, 9 + 9, center - 43, "░ ▓░▒ ▒  ░▓    ▒ ░░    ▒ ░░▒░▒░ ▒░▒░▒░ ░▒▓▒ ▒ ▒   ▒ ░░         ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒ ");
	mvwprintw(win, 10 + 9, center - 43, "  ▒ ░ ░   ▒ ░    ░     ▒ ░▒░ ░  ░ ▒ ▒░ ░░▒░ ░ ░     ░        ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░ ");

	quit_panel = new_panel(win);
	update_panels();
	doupdate();
	while ((ch = getch()))
	{
		if (ch == 'y' || ch == 'Y') {
			endwin();
			system("clear");
			exit(-1);
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

void Game::check_button(void) {

	keypad(stdscr, true);
	int ch;

	if ((ch = getch()) == KEY_RIGHT && this->_hero.getY() + 1 < WIDTH) {
		this->_map[this->_hero.getX()][this->_hero.getY()] = ' ';
		this->_hero.setY(this->_hero.getY() + 1);
		this->_map[this->_hero.getX()][this->_hero.getY()] = '>';
		ch = '\0';
	} else if (ch == KEY_LEFT && this->_hero.getY() - 1 >= 0) {
		this->_map[this->_hero.getX()][this->_hero.getY()] = ' ';
		this->_hero.setY(this->_hero.getY() - 1);
		this->_map[this->_hero.getX()][this->_hero.getY()] = '>';
		ch = '\0';
	} else if (ch == KEY_UP && this->_hero.getX() - 1 >= 0) {
		this->_map[this->_hero.getX()][this->_hero.getY()] = ' ';
		this->_hero.setX(this->_hero.getX() - 1);
		this->_map[this->_hero.getX()][this->_hero.getY()] = '>';
		ch = '\0';
	} else if (ch == KEY_DOWN && this->_hero.getX() + 1 < HEIGHT) {
		this->_map[this->_hero.getX()][this->_hero.getY()] = ' ';
		this->_hero.setX(this->_hero.getX() + 1);
		this->_map[this->_hero.getX()][this->_hero.getY()] = '>';
		ch = '\0';
	} else if (ch == ' ') {
		this->_hero.attack();
	} else if (ch == 'p') {
		std::time_t start = std::time(0);
		mvaddstr(59, 202, "The game is paused... ");
		mvaddstr(61, 202, "Press P to resume the game                ");
		ch = '\0';
		halfdelay(10000);
		while (ch != 'p') {
			if ((ch = getch()) == 'p') {
				mvaddstr(61, 202, "Press P to pause the game                  ");
				mvaddstr(59, 202, "The game is running...");
				nodelay(stdscr, true);
			} else if (ch == 'q') {
				this->menuHandler();
			}
		}
		this->_start += (std::time(0) - start);
	} else if (ch == 'q') {
		std::time_t start = std::time(0);
		this->menuHandler();
		this->_start += (std::time(0) - start);
	}

	return;
}

void	Game::pushBullet(Bullet *newBullet) {

	t_bullet	*temp = this->_bulletList;

	if (this->_bulletList == nullptr) {
		this->_bulletList = new t_bullet;
		this->_bulletList->bullet = newBullet;
		this->_bulletList->next = nullptr;
	} else {
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = new t_bullet;
		temp->next->bullet = newBullet;
		temp->next->next = nullptr;
	}

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

int Game::getCycle(void) const {

	return this->_cycle;
}

void Game::setCycle(int cycle) {

	if (cycle >= 0) {
		this->_cycle += cycle;
	}

	return;
}
