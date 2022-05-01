#include "Game.h"

using namespace std;

#ifndef TEXTURES_H
#define TEXTURES_H

class Textures
{
public:
   static SDL_Texture* LoadTexture(const char* fileName);   
   static void RenderInvertedTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);
};

#endif