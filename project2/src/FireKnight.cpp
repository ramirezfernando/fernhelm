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

    SetName("Unkown");
    SetLevel(1);
    SetHealth(100);
    SetStamina(100);
}

FireKnight::FireKnight(const string path, int frames, int speed, int xpos, int ypos, string name, int level, int health, int stamina)
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
    SetStamina(stamina);
}

