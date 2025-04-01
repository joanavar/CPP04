#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:

    std::string _type;

public:
    WrongAnimal(void);
    virtual ~WrongAnimal(void);
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal(std::string type);

    WrongAnimal &operator=(const WrongAnimal &copy);
    std::string getType(void) const;
    void    makeSound(void) const;

};

#endif