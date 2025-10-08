/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:02:22 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/08 12:31:17 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main() {
	PhoneBook MyPhoneBook;
	std::string Command;

	std::getline(std::cin, Command);
	if (Command == "ADD")
		MyPhoneBook.add();
}
