#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"


class AMateria {

protected:
  std::string _type;

public:
  AMateria(void);
  AMateria(std::string const &type);
  AMateria(AMateria const &copy);

  virtual ~AMateria(void);

  AMateria &operator=(AMateria const &copy);

  std::string const &getType(void) const; //Returns the materia type

  virtual AMateria* clone(void) const = 0;
  virtual void use(ICharacter &target);
};

#endif