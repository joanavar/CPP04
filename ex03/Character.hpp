#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character(void);
  Character(std::string const &name);
  Character(Character const &copy);

  ~Character(void);

  Character &operator=(Character const &copy);

  std::string const & getName(void) const;
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  std::string _name;
  int _size;
  AMateria *_inventory[4];
};

#endif