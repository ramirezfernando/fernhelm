#include "Character.h"
#include "Textures.h"

Character::Character(const char* textureSheet, int x, int y)
{
    characterTexture = Textures::LoadTexture(textureSheet);

    xpos = x;
    ypos = y;
    /*
    name = "Unknown";
    level = 1;
    health = 100;
    */
}
Character::Character(string _path, int numFrames, int _speed, int x, int y)
{
    //const char* file = ((_folder + "/" + _action + "/" + _action + "_" + to_string(1) + ".png").c_str());
    string filename = path+"/"+"1.png";
    const char* file = filename.c_str();
    characterTexture = Textures::LoadTexture(file);

    xpos = x;
    ypos = y;

    path = _path;
    frames = numFrames;
    speed = _speed;
    animated = true;
    count = 0;
}

void Character::Update()
{
    // implement movement animation
    if (animated)
    {
       if (count <= frames)
       {
        // conversions because "LoadTexture" takes a "const char*" as input
        // ex path = "assests/FireKnight/1_atk"
        // then filename would be "assests/FireKnight/1_atk/(count).png"
        string filename = path+"/"+ to_string(count) + ".png";
        const char* file = filename.c_str();
        characterTexture = Textures::LoadTexture(file);
        SDL_Delay(speed);
        count++;
       } 
       else 
       {
           // count = 1 because all my file names start at 1
            count = 1;
       }
        
    }

    
    //xpos++;
    //SDL_Delay(1000/25);
    //ypos++;
    //SDL_Delay(1000/25);

    srcRect.h = 200;
    srcRect.w = 300;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w * 2;
}
void Character::Render()
{
    SDL_RenderCopy(Game::renderer, characterTexture, &srcRect, &destRect);
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