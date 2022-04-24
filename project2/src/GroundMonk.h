#include "Character.h"

class GroundMonk : public Character
{
    public:
        // Constructor
        GroundMonk(const string _path, int _frames, int _speed, int xpos, int ypos, string name, int level, int health, int stamina);
        // Actions
        void UpperCut(const string _path, int _frames, int _speed);
        void RockSpike(const string _path, int _frames, int _speed);
        void RockCrush(const string _path, int _frames, int _speed);
        void Meditate(const string _path, int _frames, int _speed);
};