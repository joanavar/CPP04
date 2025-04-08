#include "Ice.hpp"
#include "AMateria.hpp"

/*
* Constructors
 */
Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::Ice(Ice const &copy) : AMateria(copy) {}

/*
* Destructor
 */
Ice::~Ice(void) {}

/*
* Overload operator
 */
Ice &Ice::operator=(Ice const &copy)
{
  if (this != &copy) 
    AMateria::operator=(copy);
  return *this;
}

/*
* Mandatory member functions
 */
AMateria* Ice::clone(void) const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at "
            << target.getName() << " *" << std::endl;
}