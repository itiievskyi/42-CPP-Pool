/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaGun.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:19:01 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/05 14:19:02 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAGUN_H
# define MEGAGUN_H

# include <iostream>
# include "AWeapon.hpp"

class MegaGun : public AWeapon {

public:

	MegaGun(void);
	MegaGun(MegaGun const &src);
	MegaGun &operator=(MegaGun const &src);
	virtual ~MegaGun(void);

	void attack(void) const;

};

#endif
