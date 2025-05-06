#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "colors.hpp"

int main()
{
IMateriaSource* src = new MateriaSource();
std::cout<<"hola\n";
src->learnMateria(new Ice());
std::cout<<"hola\n";

src->learnMateria(new Cure());
std::cout<<"hola\n";

ICharacter* me = new Character("me");
std::cout<<"hola\n";

AMateria* tmp;
std::cout<<"hola\n";

tmp = src->createMateria("Ice");
std::cout<<"hola\n";

me->equip(tmp);
std::cout<<"hol2\n";

tmp = src->createMateria("Cure");
std::cout<<"hola\n";

me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}