#include "Character.h"
 
Character::Character()
{
    name = "Unkown";
    level = 1;
    health = 100;
}

Character::Character(string _name, int _level, int _health)
{
    name = _name;
    level = _level;
    health = _health;
}

void Character::setName(string _name)
{
    name = _name;
}
void Character::setLevel(int _level)
{
    level = _level;
}
void Character::setHealth(int _health)
{
    health = _health;
}

string Character::getName()
{
    return name;
}
int Character::getLevel()
{
    return level;
}
int Character::getHealth()
{
    return health;
}