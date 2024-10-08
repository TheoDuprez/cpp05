/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:06:44 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/14 17:34:32 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signature;
	const unsigned int _requireGradeToSign;
	const unsigned int _requireGradeToExecute;

public:
	AForm(void);
	AForm(const std::string name, const unsigned int requireGradeToSign, const unsigned int requireGradeToExecute);
	AForm(const AForm &obj);
	AForm& operator=(const AForm &obj);
	virtual ~AForm(void);

	void			beSigned(Bureaucrat &bureaucrat);
	const			std::string getName(void) const;
	bool			getSignature(void) const;
	unsigned int	getRequireGradeToSign(void) const;
	unsigned int	getRequireGradeToExecute(void) const;
	virtual void	execute(const Bureaucrat& executor) const = 0;
	void			checkForExec(const Bureaucrat& bureaucrat) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NoSignatureException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class BadGradeException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class fileErrorException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class failRobotomyException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif
