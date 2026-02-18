/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:48:36 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/18 02:34:57 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("defaut"), _isSigned(false), _signReq(150), _execReq(150){}

AForm::AForm(const std::string& name, int signReq, int execReq):
	_name(name), _isSigned(false), _signReq(signReq), _execReq(execReq){
	if (signReq > 150 || execReq > 150)
		throw AForm::GradeTooLowException();
	if (signReq < 1 || execReq < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other):
	_name(other._name), _isSigned(other._isSigned), _signReq(other._signReq), _execReq(other._execReq){}

AForm &AForm::operator=(const AForm &other){
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return *this;
}

const std::string&AForm::getName() const{
	return _name;
}

const int AForm::getSignReq() const{
	return _signReq;
}
const int AForm::getExecReq() const{
	return _execReq;
}

const bool AForm::getIsSigned() const {
	return _isSigned;
}

void AForm::beSigned(Bureaucrat &b){
	if (b.getGrade() > _signReq)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw(){
	return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw(){
	return "Grade too Low";
}

const char *AForm::FormNotSignedException::what() const throw(){
	return "Form not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& f){
	out << "AForm name: " << f.getName()
		<< "\nIs signed: " << (f.getIsSigned() ? "true" : "false")
		<< "\nSign req grade: " << f.getSignReq()
		<< "\nExecution req grade: " << f.getExecReq() << std::endl;
	return out;
}

AForm::~AForm(){}
