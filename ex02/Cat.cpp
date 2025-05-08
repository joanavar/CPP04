#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
    brain = new Brain();
}
Cat::~Cat(void) 
{ 
    std::cout << "Cat destructor called" << std::endl;
    delete brain;    
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain();
    *brain = *(copy.brain); // preguntar a fede diferencia de esto a brain* = (*copy.brain);
}
Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete brain;
        brain = new Brain();
        *brain = *(copy.brain);
    }

    return *this;
}

void Cat::makeSound(void)const {std::cout << "Miau\n";}

void Cat::setIdea(std::string idea) {
	if (!brain) {
		std::cout << "Error " << _type << " has no brain" << std::endl;
		return ;
	}
	brain->setIdea(idea);
}

void Cat::getIdea(void) const {
	if (!brain) {
		std::cout << "Error " << _type << " has no brain" << std::endl;
		return ;
	}
	brain->getIdea();
}

void Cat::getIdea(int nbIdea) const {
	if (!brain) {
		std::cout << "Error " << _type << " has no brain" << std::endl;
		return ;
	}
	brain->getIdea(nbIdea);
}