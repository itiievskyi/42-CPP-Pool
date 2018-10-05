/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WastelandBeast.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:23:25 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/05 14:23:27 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WASTELANDBEAST_H
# define WASTELANDBEAST_H

# include <iostream>
# include "Enemy.hpp"

class WastelandBeast : public Enemy {

public:

	WastelandBeast(void);
	WastelandBeast(WastelandBeast const &src);
	WastelandBeast &operator=(WastelandBeast const &src);
	virtual ~WastelandBeast(void);

};

#endif
