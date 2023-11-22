/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:37:02 by tduprez           #+#    #+#             */
/*   Updated: 2023/11/22 13:18:10 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	testGrades("testGrades", 1);

	try
	{
		for (int i = 0; i < 160; i++)
		{
			std::cout << "Grade decremented : " << testGrades << std::endl;
			testGrades.decrementGrade();
		}
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;

	try
	{
		for (int i = 0; i < 160; i++)
		{
			std::cout << "Grade incremented : " << testGrades << std::endl;
			testGrades.incrementGrade();
		}
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	testTooLow("testTooLow", 160);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	testTooHigh("testTooHigh", -150);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
