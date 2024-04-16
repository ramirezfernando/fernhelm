#include "Textures.h"
#include <string>
SDL_Texture* Textures::LoadTexture(const char* texture) 
{
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* text = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return text;
}

void Textures::RenderInvertedTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(Game::renderer, texture, &src, &dest, 0.0, NULL, flip);
}


