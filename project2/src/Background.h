#include "Game.h"

using namespace std;

#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background
{
public:
    Background(const char* background, int xpos, int ypos);
    ~Background();
    void Update();
    void Render();


private:
    SDL_Texture* backgroundTexture;
    SDL_Rect srcRect, destRect;
    int xpos;
    int ypos;
};

#endif