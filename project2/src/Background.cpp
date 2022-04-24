#include "Textures.h"
#include "Background.h"

Background::Background(const char* background, int x, int y)
{
    backgroundTexture = Textures::LoadTexture(background);
    xpos = x;
    ypos = y;
}
Background::~Background()
{
    SDL_DestroyTexture(backgroundTexture);
}
void Background::Update()
{
    srcRect.h = 640;
    srcRect.w = 800;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
}
void Background::Render()
{
    SDL_RenderCopy(Game::renderer, backgroundTexture, &srcRect, &destRect);
}