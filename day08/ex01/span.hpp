/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:18:58 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/11 20:18:59 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <iomanip>
# include <vector>
# include <algorithm>

class Span {

public:

	Span(void);
	Span(unsigned int N);
	Span(Span const &src);
	~Span(void);
	Span &operator=(Span const &src);

	class TooFewException : public std::exception {
		public:
			TooFewException(void);
			TooFewException(const TooFewException &src);
			virtual ~TooFewException(void) throw();
			TooFewException  &operator=(const TooFewException &src);
			virtual const char *what() const throw();
	};

	class FullStoreException : public std::exception {
		public:
			FullStoreException(void);
			FullStoreException(const FullStoreException &src);
			virtual ~FullStoreException(void) throw();
			FullStoreException  &operator=(const FullStoreException &src);
			virtual const char *what() const throw();
	};

	class IdenticalNumbersException : public std::exception {
		public:
			IdenticalNumbersException(void);
			IdenticalNumbersException(const IdenticalNumbersException &src);
			virtual ~IdenticalNumbersException(void) throw();
			IdenticalNumbersException  &operator=(const IdenticalNumbersException &src);
			virtual const char *what() const throw();
	};

	unsigned int getActSize(void) const;
	unsigned int getMaxSize(void) const;

	void addNumber(int);
	void addRandRange(int min, int max, int size);

	int longestSpan(void) const;
	int shortestSpan(void) const;

private:

	std::vector<int>	_v;
	unsigned int		_maxSize;
	unsigned int		_actSize;

};

#endif
