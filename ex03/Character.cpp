#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp"

Character::Character(void) : _name("Default"), _size(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}
Character::Character(std::string const &name) : _name(name), _size(0) 
{
  for (int i = 0; i < 4; i++)
    _inventory[i] = NULL;
}

Character::Character(Character const &copy)
{
    for (int i = 0; i < 4; i++)
    {
        if (copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone();
        else
            _inventory[i] = NULL;      
    }
}

Character::~Character(void){
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

Character   &Character::operator=(Character const &copy){
    if (this != &copy){
        _name = copy._name;
        _size = copy._size;

        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i]) {delete _inventory[i]; _inventory[i] = NULL;}
            if (copy._inventory[i]) {_inventory[i] = copy._inventory[i]->clone();}
        }
    }
    return *this;
}

/*
* Mandatory member functions
 */

std::string const &Character::getName(void) const { return _name; }

void Character::equip(AMateria *m){
    if (!m) {return;}

    if (_size == 4){
        std::cout << CYN << "Inventory full. Can't equip "
              << m->getType() << " materia" << RST << std::endl;
    return; 
    }

    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i]){
            _inventory[i] = m;
            ++_size;
            break;
        }
    }
    std::cout << YLW << "Materia " << _size << "/4 "
        << m->getType() << " equiped!" << RST << std::endl;
}

void Character::unequip(int idx) {

 if (idx >= 4 || !_inventory[idx]) { return; } 
 std::cout << YLW << "Materia " << _size << "/4 " << _inventory[idx]->getType()
           << CYN << " unequiped!" << RST << std::endl;
 _inventory[idx] = NULL;
 --_size;
}

void Character::use(int idx, ICharacter &target) {
 if (idx >= 4 || !_inventory[idx]) { 
    std::cout << "hoa\n";
    return; }
//std::cout << "use\n ";
 _inventory[idx]->use(target);
}

