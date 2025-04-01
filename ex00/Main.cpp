#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

int main(void)
{
    const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* h = new WrongCat();

	std::cout<< std::endl << j->getType() << "" << std::endl;
	std::cout << i->getType() << "\n" << std::endl;
	h->makeSound(); //will output the WrongAnimal sound, not the WrongCat's!
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete h;

	return 0;
}