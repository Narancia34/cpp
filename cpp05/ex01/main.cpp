/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:38:39 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/17 16:00:21 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main() {
	std::cout << "--- Test 1: Form Grade Bounds ---" << std::endl;
	try {
		Form high("Top Secret", 0, 150); // Should fail
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	try {
		Form low("Trash Paper", 151, 150); // Should fail
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Successful Sign ---" << std::endl;
	try {
		Bureaucrat boss(1, "The Boss");
		Form tax("Tax Form", 10, 20);

		std::cout << tax << std::endl;
		boss.signForm(tax); // This should call beSigned internally
		std::cout << tax << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Failed Sign (Too Low) ---" << std::endl;
	try {
		Bureaucrat intern(150, "Poor Intern");
		Form contract("Important Contract", 1, 1);

		std::cout << contract << std::endl;
		intern.signForm(contract); // Intern rank 150 < Required rank 1
		std::cout << contract << std::endl; // Should still be unsigned
	} catch (std::exception &e) {
		std::cerr << "Unexpected catch in main: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Direct beSigned Call ---" << std::endl;
	try {
		Bureaucrat mid(1, "Mid Manager");
		Form secret("Secret Sauce", 30, 30);

		secret.beSigned(mid); // This should throw directly
	} catch (std::exception &e) {
		std::cout << "Caught direct exception: " << e.what() << std::endl;
	}

	return 0;
}
