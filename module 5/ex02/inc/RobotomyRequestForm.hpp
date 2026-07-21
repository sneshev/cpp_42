#pragma once 

#include <iostream>
#include "AForm.hpp"


class RobotomyRequestForm : public AForm {
	private:
		std::string _target;

	protected:
		void doAction() const override;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& inTarget);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
};