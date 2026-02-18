/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:29:10 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/18 17:37:18 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(NULL));
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 1: ShrubberyCreationForm" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		ShrubberyCreationForm shrubForm("home");
		Bureaucrat bob(137, "Bob");

		std::cout << shrubForm << std::endl;
		bob.signForm(shrubForm);
		bob.executeForm(shrubForm);
		std::cout << "Check for 'home_shrubbery' file!" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 2: ShrubberyCreationForm - Grade too low" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		ShrubberyCreationForm shrubForm("garden");
		Bureaucrat lowGrade(150, "LowGrade");

		lowGrade.signForm(shrubForm);
		lowGrade.executeForm(shrubForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 3: RobotomyRequestForm" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		RobotomyRequestForm robotForm("Bender");
		Bureaucrat alice(45, "Alice");

		std::cout << robotForm << std::endl;
		alice.signForm(robotForm);
		alice.executeForm(robotForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 4: RobotomyRequestForm - Grade too low to execute" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		RobotomyRequestForm robotForm("C3PO");
		Bureaucrat midGrade(50, "MidGrade");

		midGrade.signForm(robotForm);
		midGrade.executeForm(robotForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 5: PresidentialPardonForm" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		PresidentialPardonForm pardonForm("Arthur Dent");
		Bureaucrat president(5, "President");

		std::cout << pardonForm << std::endl;
		president.signForm(pardonForm);
		president.executeForm(pardonForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 6: PresidentialPardonForm - Grade too low" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		PresidentialPardonForm pardonForm("Zaphod");
		Bureaucrat lowBureaucrat(30, "LowBureaucrat");

		lowBureaucrat.signForm(pardonForm);
		lowBureaucrat.executeForm(pardonForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "TEST 7: Execute unsigned form" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		PresidentialPardonForm pardonForm("Ford Prefect");
		Bureaucrat highGrade(1, "HighGrade");

		highGrade.executeForm(pardonForm);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
