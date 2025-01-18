/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:12:54 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 15:14:48 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Target", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
	AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
std::string ShrubberyCreationForm::getClassName() const { return "ShrubberyCreationForm"; };

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getIs_Signed())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGrade_execute())
		throw AForm::GradeTooLowException();

	std::ofstream outfile(getName() + "_shrubbery");
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create file: " << getName() + "_shrubbery" << std::endl;
		return;
	}

	outfile << "                                                         ." << std::endl;
	outfile << "                                              .         ;  " << std::endl;
	outfile << "                 .              .              ;%     ;;   " << std::endl;
	outfile << "                   ,           ,                :;%  %;   " << std::endl;
	outfile << "                    :         ;                   :;%;'     .,   " << std::endl;
	outfile << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
	outfile << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	outfile << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	outfile << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	outfile << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	outfile << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	outfile << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
	outfile << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
	outfile << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
	outfile << "                          `@%%. `@%%    ;@@%;        " << std::endl;
	outfile << "                            ;@%. :@%%  %@@%;       " << std::endl;
	outfile << "                              %@bd%%%bd%%:;     " << std::endl;
	outfile << "                                #@%%%%%:;;" << std::endl;
	outfile << "                                %@@%%%::;" << std::endl;
	outfile << "                                %@@@%(o);  . '         " << std::endl;
	outfile << "                                %@@@o%;:(.,'         " << std::endl;
	outfile << "                            `.. %@@@o%::;         " << std::endl;
	outfile << "                               `)@@@o%::;         " << std::endl;
	outfile << "                                %@@(o)::;        " << std::endl;
	outfile << "                               .%@@@@%::;         " << std::endl;
	outfile << "                               ;%@@@@%::;.          " << std::endl;
	outfile << "                              ;%@@@@%%:;;;. " << std::endl;
	outfile << "                          ...;%@@@@@%%:;;;;,..      *https://ascii.co.uk/art/tree" << std::endl;

	outfile.close();
	std::cout << "Shrubbery created in: " << getName() + "_shrubbery" << std::endl;
}
