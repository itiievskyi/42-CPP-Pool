/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:43:46 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/10 17:43:48 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <iostream>
# include <string>

class Converter {

public:

	Converter(std::string target);
	Converter(void);
	Converter(Converter const &src);
	~Converter(void);
	Converter &operator=(Converter const &src);

	class ImpossibleConversionException : public std::exception {

		public:
			ImpossibleConversionException(void);
			ImpossibleConversionException(const ImpossibleConversionException &src);
			virtual ~ImpossibleConversionException(void) throw();
			ImpossibleConversionException  &operator=(const ImpossibleConversionException &src);
			virtual const char    *what() const throw();
	};

	operator int(void) const;
	operator float(void) const;
	operator double(void) const;

	std::string getTarget(void) const;

private:

	std::string		_target;

};

#endif
