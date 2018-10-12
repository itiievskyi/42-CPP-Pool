/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:35:34 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/11 18:35:36 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <iterator>

int main(void) {

	std::cout << "************** MutantStack ************" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "************** std::list ************" << std::endl;

	std::list<int> l_mstack;

	l_mstack.push_back(5);
	l_mstack.push_back(17);

	std::cout << l_mstack.back() << std::endl;

	l_mstack.pop_back();

	std::cout << l_mstack.size() << std::endl;

	l_mstack.push_back(3);
	l_mstack.push_back(5);
	l_mstack.push_back(737);


	std::list<int>::iterator l_it = l_mstack.begin();
	std::list<int>::iterator l_ite = l_mstack.end();

	++l_it;
	--l_it;

	while (l_it != l_ite) {
		std::cout << *l_it << std::endl;
		++l_it;
	}

	std::cout << "************** SWAP in MutantStack ************" << std::endl;

	MutantStack<int> cloneMstack;

	std::cout << "The size of mstack: " <<mstack.size() << std::endl;
	std::cout << "The size of cloneMstack: " <<cloneMstack.size() << std::endl;

	mstack.swap(cloneMstack);

	std::cout << "The size of mstack: " <<mstack.size() << std::endl;
	std::cout << "The size of cloneMstack: " <<cloneMstack.size() << std::endl;

	std::cout << "************** Another in MutantStack ************" << std::endl;

	std::stack<int> s(mstack);
	std::cout << "The size of stack s (clonned from mstack): " <<s.size() << std::endl;

	MutantStack<int> assignStack = cloneMstack;
	std::cout << "The size of stack assignStack (assigned form cloneMstack): " <<assignStack.size() << std::endl;

	return 0;
}
