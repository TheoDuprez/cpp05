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

AForm::AForm(void): _name("AForm"), _signature(false), _requireGradeToSign(1), _requireGradeToExecute(15)
{
	std::cout << "AForm constructor" << std::endl;
	return ;
}

AForm::AForm(const std::string name, const unsigned int requireGradeToSign, const unsigned int requireGradeToExecute): \
_name(name), _signature(false), _requireGradeToSign(requireGradeToSign), _requireGradeToExecute(requireGradeToExecute)
{
	if (static_cast<int>(this->_requireGradeToExecute) > 150 || static_cast<int>(this->_requireGradeToSign) > 150)
		throw AForm::GradeTooLowException();
	if (static_cast<int>(this->_requireGradeToExecute) < 1 || static_cast<int>(this->_requireGradeToSign) < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm values constructor" << std::endl;
	return ;
}

AForm::AForm(const AForm& obj): _name(obj.getName()), _requireGradeToSign(obj.getRequireGradeToSign()), _requireGradeToExecute(obj.getRequireGradeToExecute())
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

void	AForm::checkForExec(const Bureaucrat& bureaucrat) const
{
	if (this->getSignature() == false)
		throw AForm::NoSignatureException();
	if (bureaucrat.getGrade() > this->getRequireGradeToExecute())
		throw AForm::BadGradeException();
	return ;
}

const char* AForm::NoSignatureException::what() const throw()
{
	return ("Form not signed");
}

const char* AForm::BadGradeException::what() const throw()
{
	return ("Grade to low to execute");
}


const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char*	AForm::fileErrorException::what() const throw()
{
	return ("Error with file");
}

const char*	AForm::failRobotomyException::what() const throw()
{
	return ("The robotomy failed");
}

std::ostream&	operator<<(std::ostream& out, const AForm& obj)
{
	out << "Name is : " << obj.getName() << std::endl;
	out << "The AForm is signed : " << obj.getSignature() << std::endl;
	out << "Require grade to sign : " << obj.getRequireGradeToSign() << std::endl;
	out << "Required grade to execute : " << obj.getRequireGradeToExecute();
	return (out);
}
