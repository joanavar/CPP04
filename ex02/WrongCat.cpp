#include "WrongCat.hpp"


WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat default copy constructor called" << std::endl;
}


WrongCat::~WrongCat(void) { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy) {
		WrongAnimal::operator=(copy);
	}
	return *this;
}