/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:15:15 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/10 20:15:16 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_H
# define C_H

# include "Base.hpp"

class C : public Base {

public:

	C(void);
	C(C &obj);
	C &operator=(C const &r);
	virtual ~C(void);

};

#endif
