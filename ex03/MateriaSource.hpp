#ifndef MATERIASOURCE_HPP
# define MATERIASOUERCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
  MateriaSource(void);
  MateriaSource(MateriaSource const &copy);

  ~MateriaSource(void);

  MateriaSource &operator=(MateriaSource const &copy);

  void learnMateria(AMateria*);
  AMateria* createMateria(std::string const & type);

private:
  int _size;
  AMateria *_array[4];
};

#endif
