#include "Character.h"
#include "Textures.h"
class FireKnight : public Character
{
    public:
        FireKnight();
        FireKnight(bool enemy);
        FireKnight(const string _path, int _frames, int _speed, int xpos, int ypos, string name, int level, int health, int _stamina, bool enemy);

        void Attack1() override;
        void Attack2() override;
        void Attack3() override;
        void Attack4() override;
        void Death() override;
        void Defend() override;
        void Idle() override;
        void TakeDamage() override;

        void SetStamina(int);
        int GetStamina();
    private:
        int stamina;
};