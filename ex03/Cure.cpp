#include "Cure.hpp"
#include "AMateria.hpp"

/*
Constructors
*/

Cure::Cure(void) : AMateria("Cure") {}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::Cure(Cure const &copy) : AMateria(copy) {}

/* DESTRUCTOR */

Cure::~Cure(void) {}

/*  Overload Operator */

Cure    &Cure::operator=(Cure const &copy)
{
    if (this != &copy)
        AMateria::operator=(copy);
    return *this;
}

/*Members functions */

AMateria* Cure::clone(void) const { return new Cure(*this); }

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}


