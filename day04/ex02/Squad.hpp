/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:03:03 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/05 15:03:06 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_H
# define SQUAD_H

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"
# include <iostream>

class Squad : public ISquad {

public:

	Squad(void);
	Squad(Squad const &src);
	Squad &operator=(Squad const &src);
	~Squad(void);

	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);

	typedef struct		s_squad {
		ISpaceMarine	*unit;
		struct s_squad	*next;
	}					t_squad;

private:

	t_squad		*_squad;
	int			_count;

};

#endif
