/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:59:45 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/08 13:45:30 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact {
private:
	std::string FirstName;
	std::string LastName;
	std::string DarkestSecret;
	std::string PhoneNumber;
	std::string NickName;
public:
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetSecret();
	std::string GetPhoneNumber();
	std::string GetNickName();
	void SetFirstName(std::string Value);
	void SetLastName(std::string Value);
	void SetSecret(std::string Value);
	void SetPhoneNumber(std::string Value);
	void SetNickName(std::string Value);
};

#endif
