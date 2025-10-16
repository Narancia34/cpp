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

	MyPhoneBook.SetIndex(0);
	while (Command != "EXIT")
	{
		Command = getinfo("enter one of the three commands [ADD] [SEARCH] [EXIT]: ", false);
		if (Command == "ADD")
			MyPhoneBook.add();
		else if (Command == "SEARCH")
			MyPhoneBook.search();
		else if (Command == "EXIT")
			return 0;
	}
}
