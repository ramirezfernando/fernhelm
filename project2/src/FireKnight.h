#include "Character.h"

class FireKnight : public Character
{
    public:
        FireKnight();
        FireKnight(const string _path, int _frames, int _speed, int xpos, int ypos, string name, int level, int health, int stamina);

};