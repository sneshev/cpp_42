#pragma once 

#include <iostream>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	protected:
		void doAction() const override;

	public:
		ShrubberyCreationForm(const std::string& inTarget);
		~ShrubberyCreationForm();
};