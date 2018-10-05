/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:05:59 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/05 16:06:00 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_H
# define TACTICALMARINE_H

# include "ISpaceMarine.hpp"
# include <iostream>

class TacticalMarine : public ISpaceMarine {

public:

	TacticalMarine(void);
	TacticalMarine(TacticalMarine const &src);
	TacticalMarine &operator=(TacticalMarine const &src);
	~TacticalMarine(void);

	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
