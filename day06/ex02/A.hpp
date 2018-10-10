/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:14:54 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/10 20:14:55 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_H
# define A_H

# include "Base.hpp"

class A : public Base {

public:

	A(void);
	A(A &obj);
	A &operator=(A const &r);
	virtual ~A(void);

};

#endif
