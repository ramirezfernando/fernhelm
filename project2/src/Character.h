#include "Game.h"
#include <string>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
    //Character(const char* textureSheet, int xpos, int ypos, string name, int level, int health, int stamina);
    //Character(const string _path, int _frames, int _speed, int xpos, int ypos, string name, int level, int health, int stamina);
    //Character(const string _path, int _frames, int _speed);
    ~Character();


    void Update();
    void Render();
    void Clean();

    void SetTexture(const char *);
    void SetSourceRect(SDL_Rect);
    void SetDestinationRect(SDL_Rect);
    void SetXPos(int);
    void SetYPos(int);

    void SetPath(string);
    void SetFrames(int);
    void SetSpeed(int);
    void SetCount(int);

    void SetName(string);
    void SetLevel(int);
    void SetHealth(int);
    void SetStamina(int);

    SDL_Texture* GetTexture();
    SDL_Rect GetSourceRect();
    SDL_Rect GetDestinationRect();
    int GetXPos();
    int GetYPos();

    string GetPath();
    int GetFrames();
    int GetSpeed();
    int GetCount();

    string GetName();
    int GetLevel();
    int GetHealth();
    int GetStamina();

    // Actions every character that inherits does
    void Idle(const string _path, int _frames, int _speed);
    void TakeDamage(const string _path, int _frames, int _speed);
    void Defend(const string _path, int _frames, int _speed);
    void Death(const string _path, int _frames, int _speed);


    void SaveProgress(); // file output
    void LoadProgress(string file); // file input


protected:
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