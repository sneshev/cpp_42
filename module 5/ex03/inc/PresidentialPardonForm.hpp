#pragma once 

#include <iostream>
#include "AForm.hpp"


class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	protected:
		void doAction() const override;

	public:
		PresidentialPardonForm(const std::string& inTarget);
		~PresidentialPardonForm();

		static AForm* create(const std::string& target);
};