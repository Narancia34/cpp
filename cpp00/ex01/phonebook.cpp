/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:38:18 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/08 13:47:19 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int PhoneBook::GetIndex(){
	return index;
}

void PhoneBook::SetIndex(int Value){
	index = Value;
}

std::string getinfo(std::string Prompt){
	std::string Inp;
	while (Inp.empty())
	{
		std::cout << Prompt;
		std::getline(std::cin, Inp);
		if (!Inp.empty()){
			return Inp;
		}
		std::cout << "u cant have an empty field!" << std::endl;
	}
	return Inp;
}

void PhoneBook::add(){
	std::string Inp;
	Contact Current;
	Current.SetFirstName(getinfo("First name: "));
	Current.SetLastName(getinfo("Last name :"));
	Current.SetNickName(getinfo("Nick name :"));
	Current.SetPhoneNumber(getinfo("Phone number :"));
	Current.SetSecret(getinfo("whats you're darkest secret :"));
	Contacts[index%8] = Current;
	index++;
}

void PhoneBook::search(){
	for (unsigned long i = 0; i < sizeof(Contacts) / sizeof(Contacts[0]); i++){
		std::cout << Contacts[i].GetFirstName();
	}
}
