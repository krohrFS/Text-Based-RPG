#include "Person.h" // includes any code from Person.h into this file
// which is the reason we could have left the code in the header file it self
#include <iostream>
#include <string>

/*
	structure of a class

	class Identifier {

	};

*/

class Person
{
	// Fields go here
	std::string name;
	int age;



public: // our access modifier, anything above this is going to be default to private

	// Behaviours go here

	// First we want to make a default constructor for the Person class

	/*
		Constructors share the name and punctuation of the class name it self unlike other regular methods
		Also take note that there are a few key items that are in a regular methods signature that are missing
		Since our goal is to make an object static is not present, and we're not having any form of return type because this is what gets called
		when we make our object kind of like if we make an int

		int x; There is code in the int class similar in idea to this
		
		ClassName(paramList)
		{

		}
	
	*/
	// Default constructor
	Person()
	{
		// We currently have no fields to alter but we want to know that this is run so we're going to have an output
		std::cout << "Person object made" << std::endl;
		name = "Karl";
		age = 34;
	}

	// Now we're going to overload the constructor - just like normal methods constructors can be overloaded as many times as you want
	// provided the parameter list is different each time
	Person(std::string _name, int _age)
	{
		std::cout << "Person made using overloaded constructor" << std::endl;
		
		// assign our fields - NOT the parameters
		name = _name;
		age = _age;

		// If we want we can also output these values
		std::cout << "name: " << name << std::endl;
		std::cout << "age: " << age << std::endl;
		
	}

	// Getters
	// Getters will return a field generally and its return must match that of the field - no parameters
	std::string GetName()
	{
		return name;
	}

	int GetAge()
	{
		return age;
	}

	// Setters
	// Setters have no return so void, and they'll have 1 parameter that shares a type of the field that you are altering
	void SetName(std::string _name)
	{
		name = _name;
	}

	void SetAge(int _age)
	{
		age = _age;
	}

	// Now for behaviors/methods that a Person can do
	void HasBirthDay()
	{
		// Now if we really wanted to we could above make a field for birth date and we could have a if structure around that date
		// Compare the month/day of the birthdate field to the current date today if the month and day are the same we can add 1 to age
		// If we have time later on we can do this

		age++; // ++ is the iterator/increment operator it will add 1 to whatever the operator is attached to
	}

	void Greeting()
	{
		std::cout << "Hello! My name is " << name << "." << std::endl;
	}

	void Dialogue(std::string message)
	{
		std::cout << name << ": " << message << std::endl;
	}
};
