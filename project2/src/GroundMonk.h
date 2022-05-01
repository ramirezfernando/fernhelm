#include "Character.h"

class GroundMonk : public Character
{
    public:
        // Constructor
        GroundMonk();
        GroundMonk(const string _path, int _frames, int _speed, int xpos, int ypos, string name, int level, int health, int _chakra);

        // Actions
        /*
        void UpperCut();
        void RockSpike(const string _path, int _frames, int _speed);
        void RockCrush(const string _path, int _frames, int _speed);
        void Meditate(const string _path, int _frames, int _speed);
        */
        void Attack1() override;
        void Attack2() override;
        void Attack3() override;
        void Attack4() override;
        void Death() override;
        void Defend() override;
        void Idle() override;
        void TakeDamage() override;

        void SetChakra(int);
        int GetChakra();
    private:
        int chakra;
};