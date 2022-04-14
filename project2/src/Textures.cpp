#include "Textures.h"

SDL_Texture* Textures::LoadTexture(const char* texture, SDL_Renderer* ren) 
{
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* text = SDL_CreateTextureFromSurface(ren, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return text;
}