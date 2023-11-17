/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:06:44 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/14 17:34:32 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signature;
		const unsigned int _requireGradeToSign;
		const unsigned int _requireGradeToExecute;

	public:
		Form(void);
		Form(const std::string name, const unsigned int requireGradeToSign, const unsigned int requireGradeToExecute);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form(void);

		void				beSigned(Bureaucrat& bureaucrat);
		const std::string	getName(void) const;
		bool				getSignature(void) const;
		unsigned int	getRequireGradeToSign(void) const;
		unsigned int	getRequireGradeToExecute(void) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Form& obj);

#endif