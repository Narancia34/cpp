/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:44:09 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/18 21:45:03 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern::~Intern() {}
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

static AForm* createShrubbery(std::string target) { return new ShrubberyCreationForm(target); }
static AForm* createRobotomy(std::string target) { return new RobotomyRequestForm(target); }
static AForm* createPardon(std::string target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(std::string name, std::string target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*functions[])(std::string) = {
        &createShrubbery,
        &createRobotomy,
        &createPardon
    };

    for (int i = 0; i < 3; i++) {
        if (formNames[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            return functions[i](target);
        }
    }

    std::cout << "Error: Intern cannot create form '" << name << "' (Unknown type)" << std::endl;
    return NULL;
}
