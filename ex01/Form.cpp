/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:17:25 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/17 14:10:41 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Form"), is_signed(false), grade_sign(5), grade_execute(8) {}

Form::Form(const Form& other) : name(other.name), grade_sign(other.grade_sign), grade_execute(other.grade_execute), is_signed(other.is_signed) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
	{
		this->name = other.name;
		this->is_signed = other.is_signed;
		this->grade_sign = other.grade_sign;
		this->grade_execute = other.grade_execute;
	}
	return *this;
}

Form::Form(std::string name, int sign, int execute) {
	this->name = name;
	this->is_signed = false;
	this 
};