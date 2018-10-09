/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:38:28 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 19:38:29 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_H
# define CENTRALBUREAUCRACY_H

# include <iostream>
# include "OfficeBlock.hpp"

class CentralBureaucracy {

public:

	CentralBureaucracy(void);
	CentralBureaucracy(CentralBureaucracy const &src);
	~CentralBureaucracy(void);

	void feedBureaucrat(Bureaucrat *bureaucrat);
	void queueUp(std::string &target);
	void doBureaucracy(void);

private:

	CentralBureaucracy &operator=(CentralBureaucracy const &src);

	typedef struct		s_queue {
		std::string		target;
		struct s_queue	*next;
	}					t_queue;

	t_queue				*_queue;
	OfficeBlock			*_hq[20];
	int					_set;
	int					_inqueue;

};

#endif
