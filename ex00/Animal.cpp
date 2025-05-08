#include "Animal.hpp"

Animal::Animal(void){std::cout << "Default constructor Animal called\n";}

Animal::~Animal(){std::cout << "Animal destructor called\n";}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Constructor Animal called\n";  
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal default copy constructor called" << std::endl;
    _type = copy.getType();
}

Animal  &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
        _type = copy.getType();

    return *this;     
}

std::string Animal::getType(void) const {return _type;}

void    Animal::makeSound(void) const
{
    std::cout << "..." << std::endl; 
}