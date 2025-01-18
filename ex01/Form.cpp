/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:17:25 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 11:09:16 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), is_signed(false), grade_sign(5), grade_execute(8) {}

Form::Form(const Form& other) : name(other.name), is_signed(other.is_signed), grade_sign(other.grade_sign), grade_execute(other.grade_execute) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		this->is_signed = other.is_signed;
	return *this;
}

Form::Form(std::string name, int sign, int execute) : name(name), is_signed(false), grade_sign(sign), grade_execute(execute) {
	if (grade_execute < 1 || grade_sign < 1)
		throw Form::GradeTooHighException();
	if (grade_execute > 150 || grade_sign > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const {return name;};
int Form::getGrade_sign() const {return grade_sign;};
int Form::getGrade_execute() const {return grade_execute;};
bool Form::getIs_Signed() const {return is_signed;};

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->grade_sign)
		is_signed = true;
	else
		throw Form::GradeTooLowException();
};

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	if (form.getIs_Signed())
		os << form.getName() << ": has already been signed, sign grade: " << form.getGrade_sign() << " execute grade: " << form.getGrade_execute();
	else
		os << form.getName() << ": has not been signed yet, sign grade: " << form.getGrade_sign() << " execute grade: " << form.getGrade_execute();
	return os;
}