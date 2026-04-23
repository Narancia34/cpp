/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:38:59 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/23 13:35:27 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <fstream>
#include <stdexcept>
#include <string>

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

void BitcoinExchange::checkDateSyntax(const std::string &date){
	if (date.length() != 10)
		throw std::runtime_error("bad date input => " + date + "\n");
	for(int i = 0; i < 10; i++){
		if (i == 4 || i == 7) {
			if (date[i] != '-')
				throw std::runtime_error("bad date input => " + date + "\n");
		} else {
			if (!std::isdigit(date[i]))
				throw std::runtime_error("bad date input => " + date + "\n");
		}
	}
}

bool BitcoinExchange::isValidDate(int year, int month, int day){
	if (year < 2009) return false;
	if (year == 2009 && month == 1 && day < 2) return false;
	if (month < 1 || month > 12) return false;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2)
	{
		bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (leap)
			daysInMonth[1] = 29;
	}
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

void BitcoinExchange::parseDate(const std::string &date){
	checkDateSyntax(date);
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8).c_str());
	if (!isValidDate(year, month, day))
		throw std::runtime_error("bad date input => " + date + "\n");
}

float BitcoinExchange::parseValue(const std::string &value){
	char* end = NULL;
	double numeric_value = strtod(value.c_str(), &end);
	while (std::isspace(*end))
		end++;
	if (*end != '\0') {
		throw std::runtime_error("value not valid => " + value + "\n");
	} else if (numeric_value > 1000) {
		throw std::runtime_error("too large a number.\n");
	} else if (numeric_value < 0) {
		throw std::runtime_error("not a positive number.\n");
	}
	return numeric_value;
}

void BitcoinExchange::evaluateBtcValue(const std::string &date, float value){
	std::map<std::string, float>::iterator it = this->_db.lower_bound(date);
	float	db_value;
	if (it == this->_db.end()) {
		--it;
		db_value = it->second;
	} else if (it->first == date) {
		db_value = it->second;
	} else {
		--it;
		db_value = it->second;
	}
	std::cout << date << " => " << value << " = " << value * db_value << "\n";
}

void BitcoinExchange::readDataBase(){
	std::ifstream db("./data.csv");
	if (!db.is_open()){
		throw std::runtime_error("can't open database!\n");
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

void BitcoinExchange::validateInput(std::string path){
	std::ifstream input_file(path.c_str());
	if (!input_file.is_open())
		throw std::runtime_error("can't open file!\n");
	std::string line;
	std::getline(input_file, line);
	while(std::getline(input_file, line)){
		size_t pipe = line.find(" | ");
		if (pipe == std::string::npos){
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pipe);
		try {
			parseDate(date);
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what();
			continue;
		}
		std::string value = line.substr(pipe + 3);
		try {
			float numeric_value = parseValue(value);
			evaluateBtcValue(date, numeric_value);
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what();
			continue;
		}
	}
	input_file.close();
}
