/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:48:36 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/18 02:35:35 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("defaut"), _isSigned(false), _signReq(150), _execReq(150){}

Form::Form(const std::string& name, int signReq, int execReq):
	_name(name), _isSigned(false), _signReq(signReq), _execReq(execReq){
	if (signReq > 150 || execReq > 150)
		throw Form::GradeTooLowException();
	if (signReq < 1 || execReq < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &other):
	_name(other._name), _isSigned(other._isSigned), _signReq(other._signReq), _execReq(other._execReq){}

Form &Form::operator=(const Form &other){
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return *this;
}

const std::string&Form::getName() const{
	return _name;
}

const int Form::getSignReq() const{
	return _signReq;
}
const int Form::getExecReq() const{
	return _execReq;
}

const bool Form::getIsSigned() const {
	return _isSigned;
}

void Form::beSigned(Bureaucrat &b){
	if (b.getGrade() > _signReq)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw(){
	return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw(){
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& f){
	out << "Form name: " << f.getName()
		<< "\nIs signed: " << (f.getIsSigned() ? "true" : "false")
		<< "\nSign req grade: " << f.getSignReq()
		<< "\nExecution req grade: " << f.getExecReq() << std::endl;
	return out;
}

Form::~Form(){}
