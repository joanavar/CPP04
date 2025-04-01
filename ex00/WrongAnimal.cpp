#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(void) 
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) 
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) 
{
	std::cout << "WrongAnimal default copy constructor called" << std::endl;
	_type = copy.getType();
}

WrongAnimal::~WrongAnimal(void) { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) 
{
	if (this != &copy)
		_type = copy.getType();
	return *this;
}

std::string WrongAnimal::getType(void) const { return _type; }

void WrongAnimal::makeSound(void) const { std::cout << "Sound of wrong Animal" << std::endl; }