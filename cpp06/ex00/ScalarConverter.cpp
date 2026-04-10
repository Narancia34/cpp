/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:10:19 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/10 18:18:39 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <stdlib.h>

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){ (void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return *this;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}

void ScalarConverter::convertPseudoLiteral(const std::string &literal){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nanf" || literal == "+inff" || literal == "-inff"){
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
    }
    else{
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string &literal) {
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

void ScalarConverter::convertChar(const std::string &literal){
    char c = literal[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

bool ScalarConverter::isInt(const std::string &literal) {
    int i = 0;
    int j = literal.length();
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    while (i < j) {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

void	ScalarConverter::convertInt(const std::string& literal) {
	char* end;
	long i = std::strtol(literal.c_str(), &end, 10);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	if (*end != '\0' || i < INT_MIN || i > INT_MAX) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << '\n'
			<< "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		return;
	}
	char c = static_cast<char>(i);
	if (i < 0 || i > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(c)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	std::cout << "int: " << i << '\n'
			  << "float: " << std::fixed << std::setprecision(1) << f << "f" << '\n'
			  << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    int l = literal.length();
    if (l < 2 || literal[l - 1] != 'f')
        return false;
    int i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    bool hasDecimal = false;
    bool hasDigits = false;
    while (i < l - 1) {
        if (literal[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (std::isdigit(literal[i])) {
            hasDigits = true;
        } else {
            return false;
        }
        i++;
    }
    return hasDigits; 
}

void ScalarConverter::convertFloat(const std::string &literal){
	float f = std::strtof(literal.c_str(), NULL);
	char c = static_cast<char>(f);
	double d = static_cast<double>(f);
	if (f < 0 || f > 127){
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(c)) {
		std::cout << "char: non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else {
		int i = static_cast<int>(f);
		std::cout << "int: " << i << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n"
		<< "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    int l = literal.length();
    int i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;

    bool hasDecimal = false;
    bool hasDigits = false;

    while (i < l) {
        if (literal[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (std::isdigit(literal[i])) {
            hasDigits = true;
        } else {
            return false;
        }
        i++;
    }
    return (hasDigits && hasDecimal); 
}

void ScalarConverter::convertDouble(const std::string &literal){
	double d = std::strtod(literal.c_str(), NULL);
	char c = static_cast<char>(d);
	float f = static_cast<float>(d);
	if (d < 0 || d > 127){
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(c)) {
		std::cout << "char: non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else {
		int i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n"
		<< "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
    if (isPseudoLiteral(literal))
        convertPseudoLiteral(literal);
    else if (isChar(literal))
        convertChar(literal);
    else if (isInt(literal))
        convertInt(literal);
    else if (isFloat(literal))
        convertFloat(literal);
    else if (isDouble(literal))
        convertDouble(literal);
    else
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
}
