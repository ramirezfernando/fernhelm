#include "Character.h"

class WaterPriestess : public Character
{
    public:
        WaterPriestess();
        WaterPriestess(const string _path, int _frames, int _speed, int xpos, int ypos, string name, int level, int health, int _mana);

        void Attack1() override;
        void Attack2() override;
        void Attack3() override;
        void Attack4() override;
        void Death() override;
        void Defend() override;
        void Idle() override;
        void TakeDamage(int damage) override;

        void SetMana(int);
        int GetMana();
    private:
        int mana;
};