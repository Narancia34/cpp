/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:59:45 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/08 10:01:52 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact {
private:
	std::string FirstName;
	std::string LastName;
	std::string DarkestSecret;
	std::string PhoneNumber;
public:
	std::string getter();
};
