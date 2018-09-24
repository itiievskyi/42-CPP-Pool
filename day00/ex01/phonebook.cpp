/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:19:01 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/20 15:19:02 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

int		g_count = 0;

std::string	trnct(std::string str) {

	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	} else {
		return str;
	}

}

void		printContact(Contact entry)
{

	std::cout << "First name: " << entry.getFirstName() << std::endl;
	std::cout << "Last name: " << entry.getLastName() << std::endl;
	std::cout << "Nickname: " << entry.getNickName() << std::endl;
	std::cout << "Login: " << entry.getLogin() << std::endl;
	std::cout << "Postal address: " << entry.getAddress() << std::endl;
	std::cout << "Email address: " << entry.getEmail() << std::endl;
	std::cout << "Phone number: " << entry.getPhone() << std::endl;
	std::cout << "Birthday date: " << entry.getBirthday() << std::endl;
	std::cout << "Favorite meal: " << entry.getMeal() << std::endl;
	std::cout << "Underwear color: " << entry.getUnderwear() << std::endl;
	std::cout << "Darkest secret: " << entry.getSecret() << std::endl;

}

void		searchContact(Contact book[]) {

	std::string		buf;

	if (g_count == 0) {
		std::cout << "There is no any saved contacts in your phonebook\n"
		<< std::endl;
		return;
	} else {
		std::cout << "---------------------------------------------\n";
		std::cout << "|   Index  |First name| Last name| Nickname |\n";
		std::cout << "---------------------------------------------\n";
		for (int i = 0; i < g_count; i++) {
			std::cout << "|" << std::setw(10) << i << "|";
			std::cout << std::setw(10) << trnct(book[i].getFirstName()) << "|";
			std::cout << std::setw(10) << trnct(book[i].getLastName()) << "|";
			std::cout << std::setw(10) << trnct(book[i].getNickName()) << "|"
			<< std::endl;
		}
		std::cout << "---------------------------------------------\n";
	}

	std::cout << "Please enter the index of preferred contact" << std::endl;
	std::cout << "(or type '-' in order to return to main menu)" << std::endl;
	std::cout << "> ";

	while (1) {
		std::getline (std::cin, buf);
		buf.erase(0, buf.find_first_not_of(" "));
		buf.erase(buf.find_last_not_of(" ") + 1);

		if (buf.length() == 1) {
			if (buf[0] == '-') {
				std::cout << "Ok, returning to the main menu...\n" << std::endl;
				return;
			} else if (buf[0] - 48 < g_count) {
				std::cout << "Here is your contact detailed info:" << std::endl;
				printContact(book[buf[0] - 48]);
				std::cout << std::endl;
				return;
			} else {
				std::cout << "Invalid index. You can now use numbers from 0 to "
				<< (g_count - 1) << std::endl;
				std::cout << "> ";
			}
		} else {
			std::cout << "Invalid index. You can now use numbers from 0 to "
			<< (g_count - 1) << std::endl;
			std::cout << "> ";
		}
		if (std::cin.eof()) {
			return;
		}
	}
}

void		addContact(Contact book[]) {

	std::string		buf;

	if (g_count > 7) {
		std::cout << "Your phonebook is full. Please try another command"
		<< std::endl;
		return;
	}

	std::cout << "Use the following fields to fill the contact:" << std::endl;
	std::cout << "First name: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setFirstName(buf);
	} else {
		return;
	}
	std::cout << "Last name: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setLastName(buf);
	} else {
		return;
	}
	std::cout << "Nickname: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setNickName(buf);
	} else {
		return;
	}
	std::cout << "Login: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setLogin(buf);
	} else {
		return;
	}
	std::cout << "Postal address: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setAddress(buf);
	} else {
		return;
	}
	std::cout << "Email address: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setEmail(buf);
	} else {
		return;
	}
	std::cout << "Phone number: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setPhone(buf);
	} else {
		return;
	}
	std::cout << "Birthday date: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setBirthday(buf);
	} else {
		return;
	}
	std::cout << "Favorite meal: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setMeal(buf);
	} else {
		return;
	}
	std::cout << "Underwear color: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setUnderwear(buf);
	} else {
		return;
	}
	std::cout << "Darkest secret: ";
	if (std::getline (std::cin, buf)) {
		book[g_count].setSecret(buf);
	} else {
		return;
	}

	std::cout << "\nGreat! Contact #" << g_count << " is saved.\n" << std::endl;

	++g_count;
}

void	type_command(void) {

	std::cout << " Type an appropriate command to perform action" << std::endl;
	std::cout << "============= ADD / SEARCH / EXIT =============" << std::endl;
	std::cout << "> ";

}

int			main(void) {

	std::string		buf;
	Contact 		book[8];

	std::cout << "====== Welcome to the Awesome Phonebook! ======" << std::endl;
	type_command();

	while (buf != "EXIT") {
		std::getline (std::cin, buf);
		if (buf == "ADD") {
			addContact(book);
		} else if (buf == "SEARCH") {
			searchContact(book);
		} else if (buf == "EXIT") {
			std::cout << "OK, erasing all the data... The program is finished"
			<< std::endl;
			return 0;
		} else if (!(std::cin.eof())) {
			std::cout << "Invalid command. [ADD / SEARCH / EXIT]\n"
			<< std::endl;
		}
		if (std::cin.eof()) {
			std::cout << "\n! Ctrl + D was pressed. Quitting the program..."
			<< std::endl;
			return 0;
		}
		std::cout << "> ";
	}

	return 0;

}
