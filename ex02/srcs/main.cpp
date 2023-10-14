/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:37:02 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/14 22:34:38 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShruberryCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

static void	testShruberryCreationForm(Bureaucrat& bureaucrat, ShruberryCreationForm& form);
static void testRobotomyRequestForm(Bureaucrat& bureaucrat, RobotomyRequestForm& form);
static void testPresidentialPardonForm(Bureaucrat& bureaucrat, PresidentialPardonForm& form);

int	main(void)
{
	ShruberryCreationForm	shruberry("shruberry");
	RobotomyRequestForm		robotomy("robotomy");
	PresidentialPardonForm	president("president");

	std::cout << "-----------------------------------------" << std::endl;

	Bureaucrat				lowLevelBureaucratShruberry("lowLevelBureaucrat", 145);
	Bureaucrat				highLevelBureaucratShruberry("highLevelBureaucrat", 137);

	testShruberryCreationForm(lowLevelBureaucratShruberry, shruberry);
	testShruberryCreationForm(highLevelBureaucratShruberry, shruberry);

	std::cout << "-----------------------------------------" << std::endl;

	Bureaucrat				lowLevelBureaucratRobotomy("lowLevelBureaucrat", 72);
	Bureaucrat				highLevelBureaucratRobotomy("highLevelBureaucrat", 45);

	testRobotomyRequestForm(lowLevelBureaucratRobotomy, robotomy);
	testRobotomyRequestForm(highLevelBureaucratRobotomy, robotomy);
	
	std::cout << "-----------------------------------------" << std::endl;

	Bureaucrat				lowLevelBureaucratPresident("lowLevelBureaucrat", 25);
	Bureaucrat				highLevelBureaucratPresident("highLevelBureaucrat", 5);

	testPresidentialPardonForm(lowLevelBureaucratPresident, president);
	testPresidentialPardonForm(highLevelBureaucratPresident, president);

	std::cout << "-----------------------------------------" << std::endl;

	return (0);
}

static void	testShruberryCreationForm(Bureaucrat& bureaucrat, ShruberryCreationForm& form)
{
	try
	{
		form.beSigned(bureaucrat);
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		form.execute(bureaucrat);
	}
	catch (const AForm::NoSignatureException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const AForm::BadGradeException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const AForm::fileErrorException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

static void testRobotomyRequestForm(Bureaucrat& bureaucrat, RobotomyRequestForm& form)
{
	try
	{
		form.beSigned(bureaucrat);
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		form.execute(bureaucrat);
	}
	catch (const AForm::NoSignatureException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const AForm::BadGradeException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const AForm::failRobotomyException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

static void testPresidentialPardonForm(Bureaucrat& bureaucrat, PresidentialPardonForm& form)
{
	try
	{
		form.beSigned(bureaucrat);
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		form.execute(bureaucrat);
	}
	catch (const AForm::NoSignatureException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const AForm::BadGradeException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

