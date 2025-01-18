/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:24:19 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 15:21:02 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Target", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
	AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
std::string RobotomyRequestForm::getClassName() const { return "RobotomyRequestForm"; };

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getIs_Signed())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGrade_execute())
		throw AForm::GradeTooLowException();
	
	std::srand(std::time(0));
	int random = std::rand() % 2;

	if (random == 0) {
		std::cout << "Bzzzz... " << getName() << " has been robotomized successfully!" << std::endl;
	}
	else 
		std::cout << "Bzzzz... " << " robotomy failed!" << std::endl;
}