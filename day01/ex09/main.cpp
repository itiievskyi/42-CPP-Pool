/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:45:31 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/25 17:45:32 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int		main(void) {

	Logger *myLogger = new Logger("testLog");

	myLogger->log("logToConsole", "Mike");
	myLogger->log("logToFile", "John");
	myLogger->log("logToFile", " ");
	myLogger->log("logToFile", "    Jack    ");
	myLogger->log("logToBuf", "Mila");

	delete myLogger;
	return 0;
}
