/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:39:54 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:39:55 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_H
# define RADSCORPION_H

# include <iostream>
# include "Enemy.hpp"

class RadScorpion : public Enemy {

public:

	RadScorpion(void);
	RadScorpion(RadScorpion const &src);
	RadScorpion &operator=(RadScorpion const &src);
	virtual ~RadScorpion(void);

};

#endif
