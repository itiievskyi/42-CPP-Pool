/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:02:58 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/05 15:02:59 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(void) {

	this->_count = 0;
	this->_squad = nullptr;
}

Squad::Squad(Squad const &src) {

	this->_count = src.getCount();
	t_squad	*temp = new t_squad;
	this->_squad = temp;
	for (int i = 0; i < this->_count; i++) {
		temp->unit = src.getUnit(i)->clone();
		temp->next = nullptr;
		temp->next = new t_squad;
		temp = temp->next;
	}
	delete temp;

	return;
}

Squad &Squad::operator=(Squad const &src) {

	if (this != &src) {
		if (this->_count > 0) {
			t_squad	*temp;
			while (this->_squad != nullptr) {
				temp = this->_squad;
				this->_squad = this->_squad->next;
				temp->unit->~ISpaceMarine();
				delete temp;
			}
		}
		this->_count = src.getCount();
		t_squad	*temp = new t_squad;
		this->_squad = temp;
		for (int i = 0; i < this->_count; i++) {
			temp->unit = src.getUnit(i)->clone();
			temp->next = nullptr;
			temp->next = new t_squad;
			temp = temp->next;
		}
		delete temp;
	}

	return *this;
}

Squad::~Squad(void) {

	if (this->_count > 0) {
		t_squad	*temp;
		int i = 0;
		while (i < this->_count && this->_squad != NULL) {
			temp = this->_squad;
			this->_squad = this->_squad->next;
			temp->unit->~ISpaceMarine();
			delete temp;
			++i;
		}
	}

	return;
}

int Squad::getCount() const {

	return this->_count;
}

ISpaceMarine *Squad::getUnit(int num) const {

	if (num < 0 || num >= this->_count) {
		return nullptr;
	} else {
		t_squad	*temp = this->_squad;
		int i = 0;
		while (i < num) {
			temp = temp->next;
			++i;
		}
		return temp->unit;
	}

	return nullptr;
}

int Squad::push(ISpaceMarine *unit) {

	t_squad	*temp = this->_squad;

	if (unit == nullptr) {
		return this->_count;
	}

	if (this->_count == 0) {
		this->_squad = new t_squad;
		this->_count += 1;
		this->_squad->unit = unit;
		this->_squad->next = nullptr;
		return this->_count;
	}

	while (temp->next != nullptr) {
		if (temp->unit == unit) {
			return this->_count;
		}
		temp = temp->next;
	}
	if (temp->unit == unit) {
		return this->_count;
	} else {
		temp->next = new t_squad;
		temp->next->unit = unit;
		temp->next->next = nullptr;
		this->_count += 1;
	}

	return this->_count;
}
