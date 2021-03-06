/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:39:36 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:39:36 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_H
# define SUPERMUTANT_H

# include <iostream>
# include "Enemy.hpp"

class SuperMutant : public Enemy {

public:

	SuperMutant(void);
	SuperMutant(SuperMutant const &src);
	SuperMutant &operator=(SuperMutant const &src);
	virtual ~SuperMutant(void);

	virtual void takeDamage(int);

};

#endif
