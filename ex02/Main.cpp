#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Colors.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void printTestHeader(const std::string& message) {
  std::cout << GREEN << message << std::endl;
  for (unsigned long i = 0; i < message.length(); i++)
    std::cout << "=";
  std::cout << RST << std::endl;
}

void printSubtitle(const std::string& message) {
  std::cout << GREEN << message << RST << std::endl;
}

void testBrain2(void) {
  printTestHeader("Create dog1");
  Dog* dog1 = new Dog();
  
  printTestHeader("Set IDEAS on dog1");
  dog1->setIdea("EAT");
  dog1->setIdea("SLEEP");
  dog1->setIdea("SNIFF");
  
  printTestHeader("Create dog2");
  Dog* dog2 = new Dog();
  
  printTestHeader("Ask for random idea on dog2");
  dog2->getIdea();
  
  printTestHeader("Clone dog1 on dog2");
  *dog2 = *dog1;
  
  printTestHeader("Get IDEA 0 on dog2");
  dog2->getIdea(0);
  printTestHeader("Get random IDEA on dog2");
  dog2->getIdea();
  printTestHeader("Get random IDEA on dog1");
  dog1->getIdea();
  
  delete dog1;
  printTestHeader("Get random IDEA from dog2 after delete dog1");
  dog2->getIdea();
  delete dog2;
}

void testBrain(void) {
  printTestHeader("Create dog1 and dog2");
  Dog* dog1 = new Dog();
  Cat* cat1 = new Cat();
  
  printTestHeader("Set IDEAS on dog1");
  dog1->setIdea("idea 1");
  dog1->setIdea("idea 2");
  dog1->setIdea("idea 3");
  
  printTestHeader("Set IDEAS on cat1");
  cat1->setIdea("walk");
  cat1->setIdea("climb");
  cat1->setIdea("eat");
  
  printTestHeader("Get random IDEA on cat1");
  cat1->getIdea();
  printTestHeader("Get IDEA 2 on dog1");
  dog1->getIdea(2);
  printTestHeader("Get random IDEA on dog1");
  dog1->getIdea();
  
  printTestHeader("Create dog2 with copy constructor");
  Dog* dog2 = new Dog(*dog1);
  
  delete dog1;
  printTestHeader("Get IDEAS 3 nd 5 from dog2 after delete dog1");
  dog2->getIdea(3);
  dog2->getIdea(5);
  
  printTestHeader("Create cat2 with assignment operator");
  Cat* cat2 = new Cat();
  *cat2 = *cat1;
  delete cat1;
  
  printTestHeader("Get IDEAS 2 and 9 from cat2 after delete cat1");
  cat2->getIdea(2);
  cat2->getIdea(9);
  
  delete dog2;
  delete cat2;
}

void testAssignment(void) {
  printTestHeader("Create one dog and one cat");
  Animal* MakeMeDog = new Cat();
  Animal* RealDog = new Dog();
  
  printTestHeader("Check types and sounds");
  std::cout << "MakeMeDog type: " << MakeMeDog->getType() << std::endl;
  std::cout << "MakeMeDog sound: ";
  MakeMeDog->makeSound();
  std::cout << std::endl;
  std::cout << "RealDog type: " << RealDog->getType() << std::endl;
  std::cout << "RealDog sound: ";
  RealDog->makeSound();
  std::cout << std::endl;
  printTestHeader("Copy MakeMeDog = RealDog");
  *MakeMeDog = *RealDog;
  printSubtitle("Test results");
  std::cout << "MakeMeDog type: " << MakeMeDog->getType() << std::endl;
  std::cout << "MakeMeDog sound: ";
  MakeMeDog->makeSound();
  std::cout << std::endl;
  std::cout << "RealDog type: " << RealDog->getType() << std::endl;
  std::cout << "RealDog sound: ";
  RealDog->makeSound();
  std::cout << std::endl;
  
  delete MakeMeDog;
  delete RealDog;
}


int main()
{
  srand(time(NULL));
  //testBrain();
  //testBrain2();
  testAssignment();


/*
  * Mandatorry test
  AAnimal *array[10];
  
  for (int i = 0; i < 10; i++) {
  	(i % 2 == 0) ? array[i] = new Dog() : array[i] = new Cat();
  }
  
  for (int i = 0; i < 10; i++) { array[i]->makeSound(); }
  
  for (int i = 0; i < 10; i++) { delete array[i]; }
  
 */
  return 0;
}