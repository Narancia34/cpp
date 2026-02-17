/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:33:30 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/17 00:37:32 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form{
private:
	const std::string _name;
	bool _isSigned;
	const int _signReq;
	const int _execReq;
public:
	Form();
	Form(const std::string& name, int signReq, int execReq);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	const std::string &getName() const;
	const int &getSignReq() const;
	const int &getExecReq() const;
	const bool &getIsSigned() const;
	void beSigned(Bureaucrat &b);
	class GradeTooHighException : public std::exception{
	private:
		std::string message;
	public:
		GradeTooHighException(const std::string &message);
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
	private:
		std::string message;
	public:
		GradeTooLowException(const std::string &message);
		virtual const char *what() const throw();
	};
};

#endif
