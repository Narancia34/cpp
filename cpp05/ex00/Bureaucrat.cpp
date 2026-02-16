/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:26:05 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/16 22:53:38 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("unnamed"), _grade(150){}

Bureaucrat::Bureaucrat(int grade, const std::string &name): _name(name){
	if (grade > 150){
		throw Bureaucrat::GradeTooLow();
	}
	else if (grade < 1){
		throw Bureaucrat::GradeTooHigh();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		_grade = other._grade;
	}
	return (*this);
}

const std::string&Bureaucrat::getName() const {
	return _name;
}

const int&Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade(){
	if(_grade -1 < 1){
		throw Bureaucrat::GradeTooHigh();
	}
	_grade--;
}
void Bureaucrat::decrementGrade(){
	if(_grade + 1 > 150){
		throw Bureaucrat::GradeTooLow();
	}
	_grade++;
}

const char* Bureaucrat::GradeTooHigh::what() const throw(){
	return "Grade too high!\n";
}

const char* Bureaucrat::GradeTooLow::what() const throw(){
	return "Grade too low!\n";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b){
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return out;
}

Bureaucrat::~Bureaucrat(){}
