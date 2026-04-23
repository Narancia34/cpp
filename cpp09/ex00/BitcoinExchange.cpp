/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:38:59 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/23 11:12:18 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
	_db(other._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this == &other) {
		return *this;
	}
	this->_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readDataBase(){
	std::ifstream db("./data.csv");
	if (!db.is_open()){
		throw std::runtime_error("can't open database\n");
	}
	std::string line;
	std::getline(db, line);
	while (std::getline(db, line)){
		if (line.empty()) continue;
		int comma = line.find(',');
		std::string date = line.substr(0, comma);
		float rate = atof(line.substr(comma + 1).c_str());
		this->_db[date] = rate;
	}
	db.close();
}
