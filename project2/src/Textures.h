#include "Game.h"

using namespace std;

#ifndef TEXTURES_H
#define TEXTURES_H

class Textures
{
public:
   static SDL_Texture* LoadTexture(const char* fileName);   
   static SDL_Texture* LoadInvertedTexture(const char* fileName);
};

#endif