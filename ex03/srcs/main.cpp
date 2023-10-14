/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:37:02 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/15 00:01:08 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShruberryCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

// static void	testShruberryCreationForm(Bureaucrat& bureaucrat, ShruberryCreationForm& form);
// static void testRobotomyRequestForm(Bureaucrat& bureaucrat, RobotomyRequestForm& form);
static void testPresidentialPardonForm(Bureaucrat& bureaucrat, AForm& form);

int	main(void)
{
	Intern		slave;
	Bureaucrat	presidential("Presidential", 1);
	AForm	*form;

	std::cout << "-----------------------------------------" << std::endl;
	try
	{
		form = slave.makeForm("Presidential", "testTarget");
	}
	catch (const Intern::BadFormException& e)
	{
		std::cout << e.what() << std::endl;
	}

	testPresidentialPardonForm(presidential, *form);

	std::cout << "-----------------------------------------" << std::endl;

	try
	{
		form = slave.makeForm("notWorking", "testTarget");
	}
	catch (const Intern::BadFormException& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----------------------------------------" << std::endl;

	delete form;
	return (0);
}

static void testPresidentialPardonForm(Bureaucrat& bureaucrat, AForm& form)
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
		std::cout << form.getName() << std::endl;
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

