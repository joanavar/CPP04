#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){ std::cout << "Default constructor Dog called\n";}

Dog::~Dog() {std::cout << "Dog destructor called\n";}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}
