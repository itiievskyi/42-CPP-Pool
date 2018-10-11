/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutOfRangeException.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:28:41 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/11 15:28:42 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTOFRANGEEXCEPTION_H
# define OUTOFRANGEEXCEPTION_H

# include <iostream>

class OutOfRangeException : public std::exception {

public:
	OutOfRangeException(void);
	OutOfRangeException(const OutOfRangeException &src);
	virtual ~OutOfRangeException(void) throw();
	OutOfRangeException  &operator=(const OutOfRangeException &src);
	virtual const char *what() const throw();
};

#endif
