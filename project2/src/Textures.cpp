#include "Textures.h"
#include <string>
SDL_Texture* Textures::LoadTexture(const char* texture) 
{
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* text = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return text;
}



