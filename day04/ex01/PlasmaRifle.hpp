/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:37:52 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/04 20:37:52 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_H
# define PLASMARIFLE_H

# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:

	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &src);
	PlasmaRifle &operator=(PlasmaRifle const &src);
	virtual ~PlasmaRifle(void);

	void attack(void) const;

};

#endif
