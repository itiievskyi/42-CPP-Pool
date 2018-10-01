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

/*
** Only for printing "Is a directory" error message (<filesystem> header is not
** available in macOS Sierra)
*/
#include <sys/stat.h>

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
			std::ifstream input;

			input.open(argv[i], std::ifstream::in);

			struct stat st;
			std::string file = argv[i];
			lstat(file.c_str(), &st);
			if (S_ISDIR(st.st_mode)) {
				std::cerr << "cat: " << argv[i] << ": Is a directory"
				<< std::endl;
			}

			if (!input.is_open()) {
				std::cerr << "cat: " << argv[i] << ": " << std::strerror(errno)
				<< std::endl;
			} else {
				buf << input.rdbuf();
				fileContent = buf.str();
				std::cout << fileContent;
			}
		}
	}

	return 0;
}
