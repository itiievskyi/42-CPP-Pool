/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:14:59 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/10 20:15:01 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_H
# define B_H

# include "Base.hpp"

class B : public Base {

public:

	B(void);
	B(B &obj);
	B &operator=(B const &r);
	virtual ~B(void);

};

#endif
