/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:18:54 by bebuber           #+#    #+#             */
/*   Updated: 2025/01/18 15:00:15 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 140);
        ShrubberyCreationForm s1("Garden");

        std::cout << std::endl << s1 << std::endl;
        b1.signForm(s1);
        b1.executeForm(s1);
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 1);
        RobotomyRequestForm r1("Robot");

        std::cout << std::endl << r1 << std::endl;
        b2.signForm(r1);
        b2.executeForm(r1);
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 1);
        PresidentialPardonForm p1("Criminal");

        std::cout << std::endl << p1 << std::endl;
        b3.signForm(p1);
        b3.executeForm(p1);
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}