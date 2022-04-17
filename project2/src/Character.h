#include "Game.h"
#include <string>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
    //Character(const char* textureSheet, int xpos, int ypos, string name, int level, int health, int stamina);
    Character(const string _path, int _frames, int _speed, int xpos, int ypos, string name, int level, int health, int stamina);
    ~Character();
    void Update();
    void Render();

    void SetPath(string);
    void SetFrames(int);
    void SetSpeed(int);
    void SetCount(int);

    void SetName(string);
    void SetLevel(int);
    void SetHealth(int);
    void SetStamina(int);

    string GetPath();
    int GetFrames();
    int GetSpeed();
    int GetCount();

    string GetName();
    int GetLevel();
    int GetHealth();
    int GetStamina();

   

    void SaveProgress(); // file output
    void LoadProgress(string file); // file input


private:
    // image/sprite variables
    SDL_Texture* characterTexture;
    SDL_Rect srcRect, destRect;
    int xpos;
    int ypos;

    // variables for animation
    string path;
    int frames;
    int speed;
    int count;

    // game variables
    string name;
    int level;
    int health;
    int stamina;
    
};

#endif