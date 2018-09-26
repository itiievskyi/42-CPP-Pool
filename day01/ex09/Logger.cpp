/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:33:03 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/26 15:33:04 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string logFile) {

	this->_logFile = logFile;

	return;
}

Logger::~Logger(void) {

	return;
}

std::string Logger::makeLogEntry(std::string name) {

	std::string	buf = name;
	std::time_t	rawtime;
	std::tm		*timeinfo;
	char		timeStamp[27];

	buf.erase(0, buf.find_first_not_of(" "));
	buf.erase(buf.find_last_not_of(" ") + 1);
	if (!buf.length()) {
		buf = "<Undefined user>";
	}

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);
	std::strftime(timeStamp, 27, "[%c] ", timeinfo);

	buf = timeStamp + buf;
	buf += " successfuly logged in.";
	return buf;
}

void Logger::logToConsole(std::string const &entry) {

	std::cout << this->makeLogEntry(entry) << std::endl;
}

void Logger::logToFile(std::string const &entry) {

	static std::ofstream output(this->_logFile, std::ios_base::app);

	if (output.good() && output.is_open()) {
		output << this->makeLogEntry(entry) << std::endl;
	} else {
		std::cout << "Error opening logfile" << std::endl;
	}
}

void Logger::log(std::string const & dest, std::string const & message) {

	std::string f[2] = {
		"logToConsole",
		"logToFile"
	};

	void (Logger::*funcs[2])(std::string const &) = {
		&Logger::logToConsole,
		&Logger::logToFile
	};

	std::string *pos = std::find(std::begin(f), std::end(f), dest);
	int num = std::distance(f, pos);

	if (num < 0 || num > 1) {
		std::cout << "Can't find the function `" << dest << "`." << std::endl;
		return;
	}

	(this->*funcs[num])(message);
}
