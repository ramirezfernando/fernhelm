#include "Game.h"
#include <string>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
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
    void SetEnemy(bool);

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
    bool GetEnemy();
    // Actions every character that inherits does
    /*
    Yes we can create a pointer to an abstract class, 
    which could be actually pointing to the objects of its derived classes. 
    In this way, a container of base class pointers can be 
    created which can also store derived class objects.
    */
    virtual void Attack1() = 0;
    virtual void Attack2() = 0;
    virtual void Attack3() = 0;
    virtual void Attack4() = 0;
    virtual void Death() = 0;
    virtual void Defend() = 0;
    virtual void Idle() = 0;
    virtual void TakeDamage(int damage) = 0;


    void SaveProgress(); // file output
    string LoadProgress(string file); // file input


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
    bool enemy = false;
};

#endif