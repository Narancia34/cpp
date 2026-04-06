/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:10:19 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/06 16:04:01 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){ (void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){(void)other;}

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
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
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
	if (*end != '\0' || i < INT_MIN || i > INT_MAX) {
		throw std::runtime_error("The integer value exceeds the limits");
	}
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	if (i < 0 || i > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(c)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	std::cout << "int: " << i << '\n'
			  << "float: " << f << "f" << '\n'
			  << "double: " << d << std::endl;
}
