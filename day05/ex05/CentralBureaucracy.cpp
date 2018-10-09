/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:38:23 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/09 19:38:24 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy() {

	std::srand(std::time(nullptr));

	for (int i = 0; i < 20; i++) {
		this->_hq[i] = new OfficeBlock;
		Intern looser;
		this->_hq[i]->setIntern(looser);
	}

	this->_queue = nullptr;
	this->_set = 0;
	this->_inqueue = 0;

	return;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &src) {

	*this = src;

	return;
}

CentralBureaucracy &CentralBureaucracy::operator=(CentralBureaucracy const &src) {

	static_cast <void>(src);

	return *this;
}

CentralBureaucracy::~CentralBureaucracy(void) {

	return;
}

void CentralBureaucracy::feedBureaucrat(Bureaucrat *bureaucrat) {

	if (this->_set < 20) {
		this->_hq[this->_set]->setSigner(*bureaucrat);
		this->_hq[this->_set]->setExecutor(*bureaucrat);
		std::cout << "Bureaucrat " << bureaucrat->getName() <<
		" (grade " << bureaucrat->getGrade() << ") found his place in block #"
		<< this->_set << std::endl;
		++this->_set;
	} else {
		std::cout << "Can't find a place for another bureaucrat :(" << std::endl;
	}
}

void CentralBureaucracy::queueUp(std::string &target) {

	t_queue	*temp = this->_queue;

	if (this->_queue == nullptr) {
		this->_queue = new t_queue;
		this->_queue->target = target;
		this->_queue->next = nullptr;
	} else {
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = new t_queue;
		temp->next->target = target;
		temp->next->next = nullptr;
	}
	++this->_inqueue;
}

void CentralBureaucracy::doBureaucracy(void) {

	std::string types[4] = {
		"presidental pardon",
		"robotomy request",
		"shrubbery creation",
		"Another bullshit"
	};

	if (this->_set == 0) {
		std::cout << "It seems like there is no any bureaucrat here... Bad." <<
		std::endl;
		return;
	}

	if (this->_inqueue == 0) {
		std::cout << "It seems like there is nobody left in queue. Well done!" <<
		std::endl;
		return;
	}

	while (this->_queue != nullptr) {

		int b = -1;

		while (++b < this->_set && this->_queue != nullptr) {

			std::cout << "Block #" << b << "> ";
			int type = (std::rand() + this->_set) % 4;

			try {
				this->_hq[b]->doBureaucracy(types[type], this->_queue->target);
			}
			catch (OfficeBlock::NoInternException &e) {
				std::cout << e.what() << std::endl;
			}
			catch (OfficeBlock::NoSignerException &e) {
				std::cout << e.what() << std::endl;
			}
			catch (OfficeBlock::NoExecutorException &e) {
				std::cout << e.what() << std::endl;
			}
			catch (Intern::UknownFormException &e) {
				std::cout << e.what() << std::endl;
			}
			catch (OfficeBlock::GradeTooLowToSignException &e) {
				std::cout << e.what() << std::endl;
			}
			catch (OfficeBlock::GradeTooLowToExecuteException &e) {
				std::cout << e.what() << std::endl;
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}

			t_queue	*temp = this->_queue;
			this->_queue = this->_queue->next;
			delete temp;
			--this->_inqueue;
		}
	}
}
