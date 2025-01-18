/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:38:31 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 15:16:11 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PresidentialPardonForm_HPP
#define  PresidentialPardonForm_HPP

#include "AForm.hpp"

class  PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const  PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const  PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const override;
		std::string getClassName() const override;
};

#endif