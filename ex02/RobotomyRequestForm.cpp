/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:24:19 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 13:34:03 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
	AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getIs_Signed())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGrade_execute())
		throw AForm::GradeTooHighException();
	
	std::srand(std::time(0));

	int random = std::rand() % 2;

	if (random == 0) {
		std::cout << "Bzzzz... " << getName() << " has been robotomized successfully!" << std::endl;
	}
	else 
		std::cout << "Bzzzz... " << getName() << " robotomy failed!" << std::endl;
	
}