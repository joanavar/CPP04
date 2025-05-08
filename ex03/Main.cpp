#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Colors.hpp"

void printTestHeader(const std::string& message) {
  std::cout << std::endl << GRN << message << std::endl;
  for (unsigned long i = 0; i < message.length(); i++)
    std::cout << "=";
  std::cout << RST << std::endl;
}

void printSubtitle(const std::string& message) {
  std::cout << GRN << message << RST << std::endl;
}

void inventoryOverflowTest()
{
  printTestHeader("===== INVENTORY OVERFLOW TEST =====");
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  me->equip(src->createMateria("Ice"));
  me->equip(src->createMateria("Cure"));
  me->equip(src->createMateria("Ice"));
  me->equip(src->createMateria("Cure"));

  AMateria* extraMateria = src->createMateria("Ice");

  me->equip(extraMateria);

  delete extraMateria;
  delete me;
  delete src;
}

void unequipTest()
{
  printTestHeader("===== UNEQUIP TEST =====");
  ICharacter* me = new Character("me");
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  AMateria* ice = src->createMateria("Ice");
  AMateria* cure = src->createMateria("Cure");
  me->equip(ice);
  me->equip(cure);
  me->use(0, *me);
  me->use(1, *me);
  me->unequip(0);
  me->unequip(1);
  delete ice;
  delete cure;
  delete me;
  delete src;
}

void characterCopyTest()
{
  printTestHeader("===== CHARACTER COPY TEST =====");
  ICharacter* original = new Character("original");
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  AMateria* ice = src->createMateria("Ice");
  original->equip(ice);
  ICharacter* copy = new Character(*dynamic_cast<Character*>(original));
  std::cout << "Using original: ";
  original->use(0, *original);
  std::cout << "Using copy: ";
  copy->use(0, *copy);
  delete original;
  delete copy;
  delete src;
}

void characterAssignmentTest()
{
  printTestHeader("===== CHARACTER ASSIGNMENT TEST =====");
  ICharacter* char1 = new Character("char1");
  ICharacter* char2 = new Character("char2");
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  AMateria* ice = src->createMateria("Ice");
  char1->equip(ice);
  std::cout << "Before assignment:\n";
  char1->use(0, *char1);
  char2->use(0, *char2);
  *dynamic_cast<Character*>(char2) = *dynamic_cast<Character*>(char1);
  std::cout << "After assignment:\n";
  char1->use(0, *char1);
  char2->use(0, *char2);
  delete char1;
  delete char2;
  delete src;
}

int main()
{
  printTestHeader("===== STANDARD TEST =====");
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("Ice");
  me->equip(tmp);
  tmp = src->createMateria("Cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
  inventoryOverflowTest();
  unequipTest();
  //characterCopyTest();
  //characterAssignmentTest();

  return 0;
}