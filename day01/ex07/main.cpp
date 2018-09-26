/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:53:18 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/26 10:53:19 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {

	std::string fileContent;
	std::string s1;
	std::string s2;
	std::string ofs;
	std::string ifs;

	if (argc == 4) {
		ifs = argv[1];
		s1 = argv[2];
		s2 = argv[3];
		ofs = argv[1];
		ofs += ".replace";
	} else {
		std::cout << "You have placed the wrong number of arguments"
		<< " so the test suit will be executed. Check out defaultTest.replace."
		<< std::endl;
		ifs = "defaultTest";
		s1 = "bad";
		s2 = "good";
		ofs = "defaultTest.replace";
	}

	std::ifstream input(ifs);

	if (!input.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return 0;
	}

	if (s1.empty()) {
		std::cout << "Error: the string to find is empty." << std::endl;
		input.close();
		return 0;
	}

	std::stringstream buf;
	buf << input.rdbuf();
	fileContent = buf.str();

	if (s1 == s2) {
		std::cout <<
		"Be careful! Strings are equal so the file content shouldn't be changed"
		<< std::endl;
	} else {
		std::size_t found;
		while ((found = fileContent.find(s1)) != std::string::npos) {
			fileContent.replace(fileContent.find(s1), s1.length(), s2);
		}
	}

	std::ofstream output(ofs);
	output << fileContent;

	input.close();
	output.close();

	return 0;
}
