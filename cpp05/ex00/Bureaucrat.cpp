/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:26:05 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/15 18:43:18 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("unnamed"), _grade(150){}

Bureaucrat::Bureaucrat(int grade, const std::string &name): _name(name){
	if (grade > 150){
		//throw gradetoolow exception
	}
	else if (grade < 1){
		//throw gradetoohigh exception
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _grade(other._grade), _name(other._name){}

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
	_grade--;
	if(_grade < 1){
		//throw gradetoohigh exception
	}
}
void Bureaucrat::decrementGrade(){
	_grade++;
	if(_grade < 150){
		//throw gradetoolow exception
	}
}
