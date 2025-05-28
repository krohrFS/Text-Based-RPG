#include "Employer.h"
#include "Person.cpp"
#include <vector>


class Employer
{
	std::string businessName;
	std::string businessAddress;
	std::vector<Person> employees;

public:

	// Default Constructor
	Employer()
	{
		std::cout << "Employer made" << std::endl;
		businessName = "Unemployed";
		businessAddress = "N/A";
	}

	// Overloaded Constructor
	Employer(std::string _businessName, std::string _businessAddress)
	{
		std::cout << "Employer made with overload" << std::endl;
		// assign the fields
		businessName = _businessName;
		businessAddress = _businessAddress;
	}

	// Getters
	std::string GetBusinessName()
	{
		return businessName;
	}

	std::string GetBusinessAddress()
	{
		return businessAddress;
	}

	std::vector<Person> GetEmployees()
	{
		return employees;
	}

	// Setters

	void SetBusinessName(std::string _businessName)
	{
		businessName = _businessName;
	}

	void SetBusinessAddress(std::string _businessAddress)
	{
		businessAddress = _businessAddress;
	}

	void AddEmployee(Person newEmployee)
	{
		employees.push_back(newEmployee); // adds the parameter to the employee vector
	}
};