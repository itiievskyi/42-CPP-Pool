/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bob.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:09:52 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:09:53 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOB_H
# define BOB_H

# include <iostream>
# include "Victim.hpp"

class Bob : public Victim {

public:

	Bob(std::string name);
	Bob(void);
	Bob(Bob const &src);
	virtual ~Bob(void);
	Bob &operator=(Bob const &src);

};

#endif
