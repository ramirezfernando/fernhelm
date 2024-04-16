#include "GroundMonk.h" 

GroundMonk::GroundMonk()
{
    string path = "assets/GroundMonk/idle";
    const char* file = path.c_str();
    SetTexture(file);
    SetXPos(-80); 
    SetYPos(20); 

    SetPath(path);
    SetFrames(6);
    SetSpeed(100);
    SetCount(1);

    SetName("Unknown");
    SetLevel(1);
    SetHealth(100);
    
    chakra = 100;
}
GroundMonk::GroundMonk(bool isEnemy, string name)
{
    if (isEnemy) {
        SetEnemy(isEnemy);
        const char* file = "assets/GroundMonk/idle";
        SetTexture(file);
        SetXPos(200);
        SetYPos(20);

        SetPath("assets/GroundMonk/idle");
        SetFrames(6);
        SetSpeed(100);
        SetCount(1);

        SetName(name);
        SetLevel(1);
        SetHealth(100);

        chakra = 100;
    }
    else {
        SetPath("assets/GroundMonk/idle");
        SetFrames(6);
        SetSpeed(100);
        SetCount(1);
        SetXPos(-80); 
        SetYPos(20); 

        SetName(name);
        SetLevel(1);
        SetHealth(100);
        chakra = 100;

        string filename = path+"/"+"1.png";
        const char* file = filename.c_str();
        SetTexture(file);
    }
}
GroundMonk::GroundMonk(bool isEnemy, string name, int level, int health, int _chakra)
{
    if (isEnemy) {
        SetEnemy(isEnemy);
        const char* file = "assets/GroundMonk/idle";
        SetTexture(file);
        SetXPos(200);
        SetYPos(20);

        SetPath("assets/GroundMonk/idle");
        SetFrames(6);
        SetSpeed(100);
        SetCount(1);

        SetName(name);
        SetLevel(level);
        SetHealth(health);
        chakra = _chakra;
    }
    else {
        SetPath("assets/GroundMonk/idle");
        SetFrames(6);
        SetSpeed(100);
        SetCount(1);
        SetXPos(-80); 
        SetYPos(20); 

        SetName(name);
        SetLevel(level);
        SetHealth(health);
        chakra = _chakra;

        string filename = path+"/"+"1.png";
        const char* file = filename.c_str();
        SetTexture(file);
    }
}

void GroundMonk::Attack1() 
{
    string filename = "assets/GroundMonk/1_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/GroundMonk/1_atk");
    SetFrames(6);
    SetCount(1);
    SetSpeed(100);
}

void GroundMonk::Attack2() 
{
    string filename = "assets/GroundMonk/2_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/GroundMonk/2_atk");
    SetFrames(12);
    SetCount(1);
    SetSpeed(100);
}

void GroundMonk::Attack3() 
{
    string filename = "assets/GroundMonk/3_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/GroundMonk/3_atk");
    SetFrames(24);
    SetCount(1);
    SetSpeed(100);
}

void GroundMonk::Attack4() 
{
    string filename = "assets/GroundMonk/4_sp_atk";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/GroundMonk/4_sp_atk");
    SetFrames(25);
    SetCount(1);
    SetSpeed(100);
}

void GroundMonk::Death()
{
    string filename = "assets/GroundMonk/death";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/GroundMonk/death");
    SetFrames(18);
    SetCount(1);
    SetSpeed(100);
}
void GroundMonk::Defend()
{
    string filename = "assets/GroundMonk/defend";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/GroundMonk/defend");
    SetFrames(13);
    SetCount(1);
    SetSpeed(100);
}
void GroundMonk::Idle()
{
    string filename = "assets/GroundMonk/idle";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/GroundMonk/idle");
    SetFrames(6);
    SetCount(1);
    SetSpeed(100);
}
void GroundMonk::TakeDamage(int damage) 
{
    string filename = "assets/GroundMonk/take_hit";
    const char* file = filename.c_str();
    SetTexture(file);
    SetPath("assets/GroundMonk/take_hit");
    SetFrames(6);
    SetCount(1);
    SetSpeed(100);

    SetHealth(health - damage);
}
void GroundMonk::SetEnergy(int energy)
{
    chakra = energy;
}
int GroundMonk::GetEnergy()
{
    return chakra;
}
void GroundMonk::PrintStats() 
{
    cout << "Character Stats:" << endl 
        <<  "> Name: " << name << endl
        <<  "> Level: " << level << endl
        <<  "> Health: " << health << endl
        <<  "> Chakra: " << chakra << endl;
}
void GroundMonk::SaveProgress(string characterType)
{
    ofstream fout("saved-data/save.txt");
    
    fout << characterType << endl;
    fout << name << endl;
    fout << level << endl;
    fout << health << endl;
    fout << chakra << endl;
}