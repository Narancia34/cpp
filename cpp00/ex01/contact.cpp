/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:41:18 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/08 13:45:21 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"


std::string Contact::GetFirstName(){
	return (FirstName);
}

std::string Contact::GetLastName(){
	return (LastName);
}

std::string Contact::GetSecret(){
	return (DarkestSecret);
}

std::string Contact::GetPhoneNumber(){
	return (PhoneNumber);
}

std::string Contact::GetNickName(){
	return (NickName);
}

void Contact::SetFirstName(std::string value){
	FirstName = value;
}

void Contact::SetLastName(std::string value){
	LastName = value;
}

void Contact::SetSecret(std::string value){
	DarkestSecret = value;
}

void Contact::SetPhoneNumber(std::string value){
	PhoneNumber = value;
}

void Contact::SetNickName(std::string value){
	NickName = value;
}
