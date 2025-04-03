#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{

		srand(time(NULL));
	//testBrain();
	//testBrain2();

/*
  * Mandatorry test
 */
	Animal *array[10];

	for (int i = 0; i < 10; i++) 
    {
        if (i % 2 == 0)
            array[i] = new Dog();
        else
            array[i] = new Cat();
	}
	for (int i = 0; i < 10; i++) 
        array[i]->makeSound(); 
	for (int i = 0; i < 10; i++)
        delete array[i];
	return 0;
}