/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:35:26 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/11 18:35:28 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <vector>

template <typename T>
int easyfind(T &container, int num) {

	std::vector<int>::iterator position;
	position = std::find(container.begin(), container.end(), num);

	if (position != container.end()) {
		return (position - container.begin());
	} else {
		return -1;
	}

}

#endif
