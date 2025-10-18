/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:51:05 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/17 17:38:06 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;

Account::Account(int initial_deposit){
	_amount = initial_deposit;
}
