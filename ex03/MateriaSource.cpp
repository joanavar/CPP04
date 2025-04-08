#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

/*
* Constructors
 */
MateriaSource::MateriaSource(void) : _size(0) {
  for (int i = 0; i < 4; i++) { _array[i] = NULL; }
}

MateriaSource::MateriaSource(MateriaSource const &other) : _size(other._size) {
  for (int i = 0; i < 4; i++) {
    _array[i] = NULL;
    if (other._array[i]) { _array[i] = other._array[i]; }
  }
}

/*
* Destructor
 */
MateriaSource::~MateriaSource(void) {
  for (int i = 0; i < 4; i++) {
    if (_array[i]) { delete _array[i]; _array[i] = NULL; }
    --_size;
  }
}

/*
* Overload operator
 */
MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  if (this != &other) {
    _size = other._size;
    for (int i = 0; i < 4; i++) {
      _array[i] = NULL;
      if (other._array[i]) { _array[i] = other._array[i]; }
    }
  }
  return *this;
}

/*
* Mandatory member functions
 */

void MateriaSource::learnMateria(AMateria *materia)
{
    if (_size == 4 || !materia) { return ;}

    _array[_size] = materia;
    ++_size;
}

AMateria* MateriaSource::createMateria(std::string const &type){
    for (int i = 0; i < 4; i++)
    {
        if (_array[i]->getType().compare(type) == 0)
            return _array[i]->clone();
    }
    
}