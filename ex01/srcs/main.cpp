/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:37:02 by tduprez           #+#    #+#             */
/*   Updated: 2023/11/22 14:46:11 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main(void)
{
	Bureaucrat	testBureaucrat("testBureaucrat", 16);
	Form		testForm("testForm", 1, 15);

	std::cout << "------------------------------------------------" << std::endl;

	std::cout << testForm << std::endl;

	std::cout << "------------------------------------------------" << std::endl;
	
	try
	{
		testForm.beSigned(testBureaucrat);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		testBureaucrat.signForm(testForm);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "------------------------------------------------" << std::endl;

	for (int i = 0; i < 15; i++)
		testBureaucrat.incrementGrade();

	try
	{
		testForm.beSigned(testBureaucrat);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		testBureaucrat.signForm(testForm);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "------------------------------------------------" << std::endl;

	try
	{
		Form	testLowException("testLowException", -150, -150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form	testHighException("testHighException", 1500, 1500);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------------------------------------------------" << std::endl;

	return (0);
}
