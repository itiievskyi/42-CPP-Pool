/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:41:05 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/24 16:41:07 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
# define PONY_H

class	Pony {

public:

	Pony(std::string name);
	~Pony(void);

	std::string	getName(void) const;
	void		setColor(std::string color);
	std::string	getColor(void) const;
	void		setHeight(int height);
	int			getHeight(void) const;

	void		introduce(void) const;

private:

	std::string	_name;
	std::string	_color;
	int			_height;

};

#endif
