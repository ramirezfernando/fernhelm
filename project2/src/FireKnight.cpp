#include "FireKnight.h"


FireKnight::FireKnight()
{
    const char* file = "assets/FireKnight/idle";
    SetTexture(file);
    SetXPos(-80);
    SetYPos(20);

    SetPath("assets/FireKnight/idle");
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);
    SetRepeat(true); // will repeat the animation

    SetName("Unknown");
    SetLevel(1);
    SetHealth(100);

    stamina = 100;
}

FireKnight::FireKnight(bool enemy)
{
    SetEnemy(enemy);
    const char* file = "assets/FireKnight/idle";
    SetTexture(file);
    SetXPos(-80);
    SetYPos(100);

    SetPath("assets/FireKnight/idle");
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);
    SetRepeat(true);

    SetName("Unknown");
    SetLevel(1);
    SetHealth(100);

    stamina = 100;
}

FireKnight::FireKnight(const string path, int frames, int speed, int xpos, int ypos, string name, int level, int health, int _stamina, bool enemy)
{
    string filename = path+"/"+"1.png";
    const char* file = filename.c_str();
    SetTexture(file);
    SetXPos(xpos);
    SetYPos(ypos);

    SetPath(path);
    SetFrames(frames);
    SetSpeed(speed);
    SetCount(1);

    SetName(name);
    SetLevel(level);
    SetHealth(health);
    SetEnemy(enemy);

    stamina = _stamina;
}

void FireKnight::Attack1() 
{
    string filename = "assets/FireKnight/1_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/1_atk");
    SetFrames(11);
    SetCount(1);
    SetSpeed(100);
    SetRepeat(false);
}

void FireKnight::Attack2() 
{
    string filename = "assets/FireKnight/2_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/2_atk");
    SetFrames(19);
    SetCount(1);
    SetSpeed(100);
    SetRepeat(false);
}

void FireKnight::Attack3() 
{
    string filename = "assets/FireKnight/3_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/3_atk");
    SetFrames(28);
    SetCount(1);
    SetSpeed(100);
    SetRepeat(false);
}

void FireKnight::Attack4() 
{
    string filename = "assets/FireKnight/4_sp_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/4_sp_atk");
    SetFrames(18);
    SetCount(1);
    SetSpeed(100);
    SetRepeat(false);
}

void FireKnight::Death()
{
    string filename = "assets/FireKnight/death";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/death");
    SetFrames(13);
    SetCount(1);
    SetSpeed(100);
    SetRepeat(false);
}
void FireKnight::Defend()
{
    string filename = "assets/FireKnight/defend";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/defend");
    SetFrames(10);
    SetCount(1);
    SetSpeed(100);
    SetRepeat(false);
}
void FireKnight::Idle()
{
    string filename = "assets/FireKnight/idle";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/idle");
    SetFrames(8);
    SetCount(1);
    SetSpeed(100);
    SetRepeat(true);
}
void FireKnight::TakeDamage() 
{
    string filename = "assets/FireKnight/take_hit";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/FireKnight/take_hit");
    SetFrames(6);
    SetCount(1);
    SetSpeed(100);
    SetRepeat(false);
}


void FireKnight::SetStamina(int _stamina)
{
    stamina = _stamina;
}

int FireKnight::GetStamina()
{
    return stamina;
}