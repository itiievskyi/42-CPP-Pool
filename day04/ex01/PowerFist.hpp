/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:38:15 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:38:15 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_H
# define POWERFIST_H

# include <iostream>
# include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:

	PowerFist(void);
	PowerFist(PowerFist const &src);
	PowerFist &operator=(PowerFist const &src);
	virtual ~PowerFist(void);

	void attack(void) const;

};

#endif
