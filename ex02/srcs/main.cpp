/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:37:02 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/14 18:21:51 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

int	main(void)
{
	Bureaucrat	testBureaucrat("testBureaucrat", 16);
	AForm		testAForm("testAForm", 1, 15);

	std::cout << "------------------------------------------------" << std::endl;

	std::cout << testAForm << std::endl;

	std::cout << "------------------------------------------------" << std::endl;
	
	try
	{
		testAForm.beSigned(testBureaucrat);
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		testBureaucrat.signForm(testAForm);
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "------------------------------------------------" << std::endl;

	for (int i = 0; i < 15; i++)
		testBureaucrat.incrementGrade();
	
	try
	{
		testAForm.beSigned(testBureaucrat);
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		testBureaucrat.signForm(testAForm);
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "------------------------------------------------" << std::endl;

	return (0);
}
