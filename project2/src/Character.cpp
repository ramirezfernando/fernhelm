#include "Character.h"
#include "Textures.h"

Character::Character(const char* textureSheet, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    characterTexture = Textures::LoadTexture(textureSheet, ren);

    xpos = x;
    ypos = y;
    /*
    name = "Unknown";
    level = 1;
    health = 100;
    */
}
void Character::Update()
{
    // implement movement animation
    xpos++;
    ypos++;

    srcRect.h = 128;
    srcRect.w = 128;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w * 2;
}
void Character::Render()
{
    SDL_RenderCopy(renderer, characterTexture, &srcRect, &destRect);
}

Character::Character(string _name, int _level, int _health)
{
    name = _name;
    level = _level;
    health = _health;
}
void Character::SetName(string _name)
{
    name = _name;
}
void Character::SetLevel(int _level)
{
    level = _level;
}
void Character::SetHealth(int _health)
{
    health = _health;
}
string Character::GetName()
{
    return name;
}
int Character::GetLevel()
{
    return level;
}
int Character::GetHealth()
{
    return health;
}