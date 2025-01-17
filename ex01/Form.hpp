/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:17:22 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/17 14:11:25 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Form : public std::exception{
	private:
		std::string name;
		bool is_signed;
		int grade_sign;
		int grade_execute;
	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		Form(std::string name, int sign, int execute);
		
		std::string getName() const;
		int getGrade_sign() const;
		int getGrade_execute() const;
		bool getIs_Signed() const;

		void beSigned(const Bureaucrat& bureaucrat);
		
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif