/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:38:18 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/29 18:58:56 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact {
private:
	std::string FirstName;
	std::string LastName;
	std::string DarkestSecret;
	std::string PhoneNumber;
public:
	std::string getter();
};

class PhoneBook {
public:
	Contact Contacts[8];
};

int CheckCommand(std::string Command) {
	if (Command == "NEW")
		return 1;
	return 0;
}

int main() {
	PhoneBook MyPhoneBook;
	std::string Command;

	std::getline(std::cin, Command);
	
}
