/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:17:25 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 15:23:52 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("AForm"), is_signed(false), grade_sign(150), grade_execute(150) {}

AForm::AForm(const AForm& other) : name(other.name), is_signed(other.is_signed), grade_sign(other.grade_sign), grade_execute(other.grade_execute) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		this->is_signed = other.is_signed;
	return *this;
}

AForm::AForm(std::string name, int sign, int execute) : name(name), is_signed(false), grade_sign(sign), grade_execute(execute) {
	if (grade_execute < 1 || grade_sign < 1)
		throw AForm::GradeTooHighException();
	if (grade_execute > 150 || grade_sign > 150)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const {return name;};
int AForm::getGrade_sign() const {return grade_sign;};
int AForm::getGrade_execute() const {return grade_execute;};
bool AForm::getIs_Signed() const {return is_signed;};
std::string AForm::getClassName() const { return "AForm"; };

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->grade_sign)
		throw AForm::GradeTooLowException();
	is_signed = true;
};

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	if (form.getIs_Signed())
		os << form.getClassName() << " for " << form.getName() << ": has already been signed, sign grade: " << form.getGrade_sign() << " execute grade: " << form.getGrade_execute();
	else
		os << form.getClassName() << " for " << form.getName() << ": has not been signed yet, sign grade: " << form.getGrade_sign() << " execute grade: " << form.getGrade_execute();
	return os;
}