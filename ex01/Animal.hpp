#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    
    std::string _type;

public:

    Animal(void);
    Animal(std::string type);
    Animal(const Animal &copy);
    virtual ~Animal();

    Animal  &operator=(const Animal &copy);
    std::string getType() const;
    virtual void makeSound(void) const;

};

#endif