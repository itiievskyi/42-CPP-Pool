/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:24:24 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/27 10:24:25 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(const int intNum);
	Fixed(const float floatNum);
	~Fixed(void);

	Fixed &operator=(Fixed const &src);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

private:

	int _fixed;
	static const int _fract;

};

std::ostream &operator<<(std::ostream &o, Fixed const &src);

#endif
