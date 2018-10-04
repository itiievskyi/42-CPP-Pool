/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:51:20 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:51:21 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_H
# define PEON_H

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim {

public:

	Peon(std::string name);
	Peon(void);
	Peon(Peon const &src);
	virtual ~Peon(void);
	Peon &operator=(Peon const &src);

	void	getPolymorphed(void) const;

};

#endif
