#include "AMateria.hpp"

/*
* Constructors
 */
AMateria::AMateria(void) : _type("AMateria") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &copy) : _type(copy._type) {}

/*
* Destructor
 */
AMateria::~AMateria(void) {}

/*
* Overload operator
 */
AMateria &AMateria::operator=(AMateria const &copy)
{
    if (this != &copy)
        _type = copy._type;
    return *this; 
    }

/*
* Mandatory member functions
 */
std::string const &AMateria::getType(void) const {   return _type; }

void AMateria::use(ICharacter& target) { (void)target; }