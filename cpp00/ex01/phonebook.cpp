/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:38:18 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/14 17:10:29 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::SetIndex(int Value){
	index = Value;
}

int ContactCount(int index)
{
	if (index < 8)
		return index;
	return 7;
}

std::string truncate(std::string str){
	if (str.length() > 9){
		return str.substr(0, 9) + ".";
	}
	return str;
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
		std::cout << "u cant leave it empty!" << std::endl;
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
	if (ContactCount(index) == 0){
		std::cout << "no info to search for" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "firstname" << "|";
	std::cout << std::setw(10) << "lastname" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < ContactCount(index) ; i++){
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(Contacts[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << truncate(Contacts[i].GetLastName()) << "|";
		std::cout << std::setw(10) << truncate(Contacts[i].GetNickName()) << std::endl;
	}
	std::string input = getinfo("input the index you wish to get more info: ");
	int searchIndex = atoi(input.c_str());
	if (searchIndex > ContactCount(index) - 1 || searchIndex < 0)
		std::cout << "invalid index" << std::endl;
	else {
		std::cout << "firstname: " << Contacts[searchIndex].GetFirstName() << std::endl;
		std::cout << "lastname: " << Contacts[searchIndex].GetLastName() << std::endl;
		std::cout << "nickname: " << Contacts[searchIndex].GetNickName() << std::endl;
		std::cout << "phonemumber: " << Contacts[searchIndex].GetPhoneNumber() << std::endl;
		std::cout << "darkest secret: " << Contacts[searchIndex].GetSecret() << std::endl;
	}
}
