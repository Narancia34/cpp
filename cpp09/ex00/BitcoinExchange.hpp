/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:20:38 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/23 12:20:22 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float> _db;
	void parseDate(const std::string &date);
	float parseValue(const std::string &value);
	void evaluateBtcValue(const std::string &date, float value);
	void checkDateSyntax(const std::string &date);
	bool isValidDate(int year, int month, int day);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void readDataBase();
	void validateInput(std::string path);
};

#endif
