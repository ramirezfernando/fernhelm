#include "Character.h"

class GroundMonk : public Character
{
    public:
        // Constructor
        GroundMonk();
        GroundMonk(bool isEnemy, string name);
        GroundMonk(bool isEnemy, string name, int level, int health, int _chakra);

        // Actions
        void Attack1() override;
        void Attack2() override;
        void Attack3() override;
        void Attack4() override;
        void Death() override;
        void Defend() override;
        void Idle() override;
        void TakeDamage(int damage) override;

        void SetEnergy(int) override;
        int GetEnergy() override;

        void PrintStats() override;
        void SaveProgress(string characterType) override;
    private:
        int chakra;
};