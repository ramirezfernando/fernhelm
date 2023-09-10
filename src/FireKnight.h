#include "Character.h"
#include "Textures.h"

class FireKnight : public Character
{
    public:
        FireKnight();
        FireKnight(bool enemy);
        FireKnight(string name);
        FireKnight(string name, int level, int health, int _stamina);

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
        int stamina;
};