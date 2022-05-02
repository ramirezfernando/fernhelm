#include "Character.h"

class WaterPriestess : public Character
{
    public:
        WaterPriestess();
        WaterPriestess(string name, int level, int health, int _mana);

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