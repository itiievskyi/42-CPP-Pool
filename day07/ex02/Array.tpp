/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 13:37:02 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/11 13:37:03 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <string>
# include <iomanip>
# include "OutOfRangeException.hpp"

template <typename T = int>
class Array {

public:
	Array(void) {
		this->_size = 0;
		this->_array = new T();
		return ;
	}

	Array(unsigned int n) {

		this->_size = n;
		this->_array = new T[n];
		int i = 0;
		while (i < static_cast<int>(n)) {
			this->_array[i] = 0;
			i++;
		}
	}

	Array(Array const &src) {

		int i = 0;
		this->_array = new T[src.size()];
		while (i < src.size()) {
			this->_array[i] = src.getArray()[i];
			i++;
		}
		this->_size = src.size();
		return;
	}

	~Array(void) {
		delete [] this->_array;
	}

	int size(void) const {
		return this->_size;
	}

	T *getArray(void) const {
		return this->_array;
	}

	Array &operator=(Array const &src) {

		int i = 0;
		this->_array = new T[src.size()];
		while (i < src.size()) {
			this->_array[i] = src.getArray()[i];
			i++;
		}
		this->_size = src.size();
		return *this;
	}

	T &operator[](int const n) {
		if (n >= this->_size || n < 0)
			throw OutOfRangeException::OutOfRangeException();
		else
			return this->_array[n];
	}

private:

	T		*_array;
	int		_size;

};

#endif
