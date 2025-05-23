#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:

    Brain* brain;
public:

    Dog(void);
    Dog(const Dog &copy);
    ~Dog();

    Dog  &operator=(const Dog &copy);
    void makeSound(void) const override;
    
    void setIdea(std::string idea);
	void getIdea(void) const; 
	void getIdea(int nbIdea) const; 
};



#endif