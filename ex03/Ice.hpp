#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

public:
  Ice(void);
  Ice(std::string const &type);
  Ice(Ice const &copy);

  ~Ice(void);

  Ice &operator=(Ice const &copy);

  AMateria* clone(void) const;
  void use(ICharacter& target);
};

#endif