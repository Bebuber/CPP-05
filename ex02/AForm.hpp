/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:17:22 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 15:11:39 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm : public std::exception{
	private:
		const std::string name;
		bool is_signed;
		const int grade_sign;
		const int grade_execute;
	public:
		AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		AForm(std::string name, int sign, int execute);
		
		std::string getName() const;
		int getGrade_sign() const;
		int getGrade_execute() const;
		bool getIs_Signed() const;

		void beSigned(Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		virtual std::string getClassName() const;
		
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif