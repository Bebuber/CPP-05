/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:12:58 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 13:04:16 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ShrubberyCreationForm_HPP
#define  ShrubberyCreationForm_HPP

#include "AForm.hpp"

class  ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const  ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const  ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;
};

#endif