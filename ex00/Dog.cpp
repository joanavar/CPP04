#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){ std::cout << "Dog Default constructor Dog called\n";}

Dog::~Dog() {std::cout << "Dog destructor called\n";}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog	&Dog::operator=(const Dog &copy)
{
	if (this != &copy)
		Animal::operator=(copy);

	return *this;
}

void	Dog::makeSound(void) const {std::cout << "Guau!!\n";}
