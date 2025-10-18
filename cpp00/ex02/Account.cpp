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
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:"
		<< _accountIndex
		<< ";amount:"
		<< _amount
		<< ";created" << std::endl;
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

int Account::getNbAccounts(){
	return _nbAccounts;
}
int Account::getTotalAmount(){
	return _totalAmount;
}
int Account::getNbDeposits(){
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(){
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

void Account::makeDeposit(int deposit){
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount - deposit
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	if (_amount < withdrawal){
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:" << "refused"
			<< std::endl;
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount + withdrawal
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	return true;
}

int Account::checkAmount()const {
	return _amount;
}
void Account::displayStatus() const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void Account::_displayTimestamp(){
	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);
	char output[50];
	strftime(output, 50, "[%Y%m%d_%H%M%S] ", &datetime);
	std::cout << output;
}
