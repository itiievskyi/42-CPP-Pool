/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:16:39 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/12 11:16:40 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

public:

	MutantStack(void) {}
	~MutantStack(void) {}
	MutantStack<T>(MutantStack<T> const & src) : std::stack<T>(src) {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() {
		return std::stack<T>::c.begin();
	}

	iterator end() {
		return std::stack<T>::c.end();
	}
};

#endif
