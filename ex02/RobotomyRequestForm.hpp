/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:23:18 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 13:24:14 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  RobotomyRequestForm_HPP
#define  RobotomyRequestForm_HPP

#include "AForm.hpp"

class  RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const  RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const  RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;
};

#endif