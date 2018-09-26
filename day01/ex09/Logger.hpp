/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:33:08 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/26 15:33:09 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

# include <iostream>
# include <fstream>

class	Logger {

public:

	Logger(std::string logFile);
	~Logger(void);

	void log(std::string const & dest, std::string const & message);

private:

	std::string makeLogEntry(std::string name);
	void logToConsole(std::string const &entry);
	void logToFile(std::string const &entry);

	std::string		_logFile;

};

#endif
