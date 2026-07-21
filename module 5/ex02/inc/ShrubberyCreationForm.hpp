#pragma once 

#include <iostream>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	protected:
		void doAction() const override;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& inTarget);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};