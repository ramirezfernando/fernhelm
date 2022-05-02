#include "WaterPriestess.h"

WaterPriestess::WaterPriestess()
{
    string path = "assets/WaterPriestess/idle";
    const char* file = path.c_str();
    SetTexture(file);
    SetXPos(-80);
    SetYPos(20);

    SetPath(path);
    SetFrames(8);
    SetSpeed(70);
    SetCount(1);

    SetName("Unknown");
    SetLevel(1);
    SetHealth(100);
    
    mana = 100;
}

WaterPriestess::WaterPriestess(const string path, int frames, int speed, int xpos, int ypos, string name, int level, int health, int _mana)
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

    mana = _mana;
}


void WaterPriestess::Attack1() 
{
    string filename = "assets/WaterPriestess/1_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/WaterPriestess/1_atk");
    SetFrames(7);
    SetCount(1);
    SetSpeed(100);
}

void WaterPriestess::Attack2() 
{
    string filename = "assets/WaterPriestess/2_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/WaterPriestess/2_atk");
    SetFrames(21);
    SetCount(1);
    SetSpeed(100);
}

void WaterPriestess::Attack3() 
{
    string filename = "assets/WaterPriestess/3_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/WaterPriestess/3_atk");
    SetFrames(28); // added image 28 from idle (1)
    SetCount(1);
    SetSpeed(100);
}

void WaterPriestess::Attack4() 
{
    string filename = "assets/WaterPriestess/4_sp_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/WaterPriestess/4_sp_atk");
    SetFrames(33); // added image 33 from idle (1)
    SetCount(1);
    SetSpeed(100);
}

void WaterPriestess::Death()
{
    string filename = "assets/WaterPriestess/death";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/WaterPriestess/death");
    SetFrames(16);
    SetCount(1);
    SetSpeed(100);
}
void WaterPriestess::Defend()
{
    string filename = "assets/WaterPriestess/defend";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/WaterPriestess/defend");
    SetFrames(12);
    SetCount(1);
    SetSpeed(100);
}
void WaterPriestess::Idle()
{
    string filename = "assets/WaterPriestess/idle";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/WaterPriestess/idle");
    SetFrames(8);
    SetCount(1);
    SetSpeed(100);
}
void WaterPriestess::TakeDamage(int damage) 
{
    string filename = "assets/WaterPriestess/take_hit";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/WaterPriestess/take_hit");
    SetFrames(7);
    SetCount(1);
    SetSpeed(100);

    SetHealth(health - damage);
}
