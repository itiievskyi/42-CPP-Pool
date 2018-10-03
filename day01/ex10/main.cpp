/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:03:35 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/01 09:03:38 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {

	if (argc == 1) {
		std::stringstream buf;
		std::string fileContent;
		std::getline (std::cin, fileContent);
		while (!(std::cin.eof())) {
			std::cout << fileContent << std::endl;
			std::getline (std::cin, fileContent);
		}
	} else {
		for (int i = 1; i < argc; i++) {

			std::stringstream buf;
			std::string fileContent;

			std::ifstream input(argv[i]);

			try {
				input.exceptions(std::ios::failbit | std::ios::badbit);
				input.seekg(0, std::ios::end);
				} catch (std::ios_base::failure &err) {
					std::cerr << "cat: " << argv[i] << ": "
					<< std::strerror(errno) << std::endl;
					continue;
				}

			try {
				errno = 0;
				std::string line;
				while (std::getline(input, line)) {}
			} catch (std::ios_base::failure &err) {
				if (errno != 0) {
					std::cerr << "cat: " << argv[i] << ": "
					<< std::strerror(errno) << std::endl;
				} else {
					std::ifstream input(argv[i]);
					buf << input.rdbuf();
					fileContent = buf.str();
				}
			}

			if (input.is_open()) {
				std::cout << fileContent;
			}
		}
	}
	return 0;
}
