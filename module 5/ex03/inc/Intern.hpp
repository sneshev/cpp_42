#pragma once

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"



const std::string forms[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

typedef AForm* (*FormCreator)(const std::string&);

const FormCreator formCreators[3] = {
	&ShrubberyCreationForm::create,
	&RobotomyRequestForm::create,
	&PresidentialPardonForm::create
};

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		
		AForm* makeForm(const std::string& inName, const std::string& inTarget);
};