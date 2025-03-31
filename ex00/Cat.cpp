#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::~Cat(void) { std::cout << "Cat destructor called" << std::endl;}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
        Animal::operator=(copy);

    return *this;
}

void Cat::makeSound(void)const {std::cout << "Miau\n";}