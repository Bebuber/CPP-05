/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:38:29 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 15:14:03 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Target", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
	AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
std::string PresidentialPardonForm::getClassName() const { return "PresidentialPardonForm"; };

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getIs_Signed())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGrade_execute())
		throw AForm::GradeTooLowException();

	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}