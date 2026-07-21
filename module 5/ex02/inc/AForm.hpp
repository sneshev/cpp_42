#pragma once

#include <exception>
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;

	protected:
		virtual void doAction() const = 0;

	public:
		AForm(const std::string& inName, int inGradeToSign, int inGradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		
		void beSigned(const Bureaucrat& b);
		void execute(const Bureaucrat& b) const;
		
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

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& s, const AForm& f);
