#include "Character.h"

class GroundMonk : public Character
{
    public:
        // Constructor
        GroundMonk();
        GroundMonk(string name, int level, int health, int _chakra);

        // Actions
        void Attack1() override;
        void Attack2() override;
        void Attack3() override;
        void Attack4() override;
        void Death() override;
        void Defend() override;
        void Idle() override;
        void TakeDamage(int damage) override;

        void SetChakra(int);
        int GetChakra();
    private:
        int chakra;
};