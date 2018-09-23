/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:08:39 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/20 16:08:41 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class	Contact {

public:

	Contact(void);
	~Contact(void);

	std::string	getFirstName(void) const;
	void 		setFirstName(std::string firstName);
	std::string	getLastName(void) const;
	void 		setLastName(std::string lastName);
	std::string	getNickName(void) const;
	void 		setNickName(std::string nickName);
	std::string	getLogin(void) const;
	void 		setLogin(std::string login);
	std::string	getAddress(void) const;
	void 		setAddress(std::string address);
	std::string	getEmail(void) const;
	void 		setEmail(std::string email);
	std::string	getPhone(void) const;
	void 		setPhone(std::string phone);
	std::string	getBirthday(void) const;
	void 		setBirthday(std::string birthday);
	std::string	getMeal(void) const;
	void 		setMeal(std::string meal);
	std::string	getUnderwear(void) const;
	void 		setUnderwear(std::string underwear);
	std::string	getSecret(void) const;
	void 		setSecret(std::string secret);

private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_login;
	std::string	_address;
	std::string	_email;
	std::string	_phone;
	std::string	_birthday;
	std::string	_meal;
	std::string	_underwear;
	std::string	_secret;

};

#endif
