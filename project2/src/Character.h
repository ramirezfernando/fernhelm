#include "Game.h"
#include <string>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
    Character(const char* textureSheet, SDL_Renderer* ren, int xpos, int ypos);
    ~Character();
    void Update();
    void Render();


    Character(string, int, int);
  

    void SetName(string);
    void SetLevel(int);
    void SetHealth(int);
    string GetName();
    int GetLevel();
    int GetHealth();
    void SaveProgress(); // file output
    void LoadProgress(); // file input

private:
    string name;
    int level;
    int health;
    
    SDL_Texture* characterTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
    int xpos;
    int ypos;
};

#endif