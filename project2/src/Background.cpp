#include "Textures.h"
#include "Background.h"

Background::Background(const char* background, int x, int y, bool _text)
{
    // Loads texture with the help of the Textures class
    backgroundTexture = Textures::LoadTexture(background);
    xpos = x;
    ypos = y;
    text = _text;
    path = std::string(background);
}

void Background::Update()
{
    if (text) {
        const char* background = path.c_str();
        backgroundTexture = Textures::LoadTexture(background);
        srcRect.h = 180;
        srcRect.w = 700;
    } else {
        srcRect.h = 640;
        srcRect.w = 800;
    }
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
void Background::Clean()
{
    SDL_DestroyTexture(backgroundTexture);
}

void Background::SetPath(string _path)
{
    path = _path;
}
string Background::GetPath()
{
    return path;
}