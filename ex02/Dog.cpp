#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{ 
	std::cout << "Default constructor Dog called\n";
	brain = new Brain();	
}

Dog::~Dog() 
{
	std::cout << "Dog destructor called\n";
	delete brain;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain();
	*brain = *(copy.brain);
}
Dog	&Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete brain;
		brain = new Brain;
		*brain = *(copy.brain);
	}

	return *this;
}

void	Dog::makeSound(void) const {std::cout << "Guau!!\n";}
