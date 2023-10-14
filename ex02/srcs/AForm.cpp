/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:24:26 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/14 17:34:52 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

AForm::AForm(void): _name("AForm"), _requireGradeToSign(1), _requireGradeToExecute(15)
{
	std::cout << "AForm constructor" << std::endl;
	return ;
}

AForm::AForm(const std::string name, const unsigned int requireGradeToSign, const unsigned int requireGradeToExecute): \
_name(name), _signature(false), _requireGradeToSign(requireGradeToSign), _requireGradeToExecute(requireGradeToExecute)
{
	std::cout << "AForm values constructor" << std::endl;
	return ;
}

AForm::AForm(const AForm& obj): _requireGradeToSign(obj.getRequireGradeToSign()), _requireGradeToExecute(obj.getRequireGradeToExecute())
{
	std::cout << "AForm copy constructor" << std::endl;
	*this = obj;
	return ;
}

AForm&	AForm::operator=(const AForm& obj)
{
	if (this != &obj)
		this->_signature = obj._signature;
	return *this;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor" << std::endl;
	return ;
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_requireGradeToSign < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	else
		this->_signature = true;
	return ;
}

unsigned int	AForm::getRequireGradeToSign(void) const
{
	return this->_requireGradeToSign;
}

unsigned int	AForm::getRequireGradeToExecute(void) const
{
	return this->_requireGradeToExecute;
}

const std::string	AForm::getName(void) const
{
	return this->_name;
}

bool	AForm::getSignature(void) const
{
	return this->_signature;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& out, const AForm& obj)
{
	out << "Name is : " << obj.getName() << std::endl;
	out << "The AForm is signed : " << obj.getSignature() << std::endl;
	out << "Require grade to sign : " << obj.getRequireGradeToSign() << std::endl;
	out << "Required grade to execute : " << obj.getRequireGradeToExecute();
	return (out);
}
