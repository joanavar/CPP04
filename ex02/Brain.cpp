#include "Brain.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Brain::Brain(void) : totalIdeas(0)
{
std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain default copy constructor called" << std::endl;

    for (int i = 0; i < 100; i++)
    {
        ideas[i] = std::string(copy.ideas[i]);
    }
    
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain asignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			if (!other.ideas[i].empty())
			{
				++totalIdeas;
				ideas[i] = other.ideas[i];
			}
		}
	}
	return *this;
}


Brain::~Brain(void) 
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(std::string &idea) {
	if (totalIdeas == 100) 
    {
		std::cout << "Brain is full" << std::endl;
		return ;
	}
	std::cout << "Idea [" << idea << "] set on possition " << totalIdeas << std::endl;
	ideas[totalIdeas++] = idea;
}

void Brain::getIdea(void) const
{
    if (!totalIdeas)
    {
        std::cout << "Brain no ideas\n";
        return ;
    }
    std::cout << ideas[rand() % totalIdeas] << std::endl;
}

void Brain::getIdea(int nbIdea) const 
{
	if (nbIdea > totalIdeas - 1) {
		std::cout << "Brain has not this many ideas yet" << std::endl;
		return ;
	}
	std::cout << "Idea: " << ideas[nbIdea] << std::endl;
}