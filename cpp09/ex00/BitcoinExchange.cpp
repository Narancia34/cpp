/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:38:59 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/23 11:55:26 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
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
		int pipe = line.find(" | ");
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
			
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what();
			continue;
		}
	}
	input_file.close();
}
