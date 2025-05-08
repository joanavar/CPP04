#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

private:

    Brain* brain;
public:

    Cat(void);
    Cat(const Cat &copy);
    ~Cat();

    Cat  &operator=(const Cat &copy);
    void makeSound(void) const override;

    void setIdea(std::string idea);
	void getIdea(void) const; 
	void getIdea(int nbIdea) const; 

};

#endif