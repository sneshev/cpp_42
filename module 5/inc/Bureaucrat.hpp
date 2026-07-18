#pragma once

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat(int inGrade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
		const int getGrade() const;
		void incrementGrade();
		void decrementGrade();
};

std::ostream& operator<<(std::ostream& s, const Bureaucrat& b);
