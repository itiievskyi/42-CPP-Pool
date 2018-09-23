/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:08:13 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/20 16:08:15 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

Contact::Contact(void) {

	return;
}

Contact::~Contact(void) {

	return;
}

std::string	Contact::getFirstName(void) const {

	return this->_firstName;
}

std::string	Contact::getLastName(void) const {

	return this->_lastName;
}

std::string	Contact::getNickName(void) const {

	return this->_nickName;
}

std::string	Contact::getLogin(void) const {

	return this->_login;
}

std::string	Contact::getAddress(void) const {

	return this->_address;
}

std::string	Contact::getEmail(void) const {

	return this->_email;
}

std::string	Contact::getPhone(void) const {

	return this->_phone;
}

std::string	Contact::getBirthday(void) const {

	return this->_birthday;
}

std::string	Contact::getMeal(void) const {

	return this->_meal;
}

std::string	Contact::getUnderwear(void) const {

	return this->_underwear;
}

std::string	Contact::getSecret(void) const {

	return this->_secret;
}

void 		Contact::setFirstName(std::string firstName) {

	this->_firstName = firstName;
}
void 		Contact::setLastName(std::string lastName) {

	this->_lastName = lastName;
}
void 		Contact::setNickName(std::string nickName) {

	this->_nickName = nickName;
}
void 		Contact::setLogin(std::string login) {

	this->_login = login;
}
void 		Contact::setAddress(std::string address) {

	this->_address = address;
}
void 		Contact::setEmail(std::string email) {

	this->_email = email;
}
void 		Contact::setPhone(std::string phone) {

	this->_phone = phone;
}
void 		Contact::setBirthday(std::string birthday) {

	this->_birthday = birthday;
}
void 		Contact::setMeal(std::string meal) {

	this->_meal = meal;
}
void 		Contact::setUnderwear(std::string underwear) {

	this->_underwear = underwear;
}
void 		Contact::setSecret(std::string secret) {

	this->_secret = secret;
}
