#pragma once

#include <exception>
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;

	public:
		Form();
		Form(const std::string& inName, int inGradeToSign, int inGradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		
		void beSigned(const Bureaucrat& b);
		
		const std::string& getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getSignedStatus() const;


		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& s, const Form& f);

