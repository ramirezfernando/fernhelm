#include "Character.h"
#include "Textures.h"

/*
Character::Character(const string _path, int _frames, int _speed, int x, int y, string _name, int _level, int _health, int _stamina)
{
    //const char* file = ((_folder + "/" + _action + "/" + _action + "_" + to_string(1) + ".png").c_str());
    string filename = _path+"/"+"1.png";
    const char* file = filename.c_str();
    characterTexture = Textures::LoadTexture(file);
    xpos = x;
    ypos = y;

    path = _path;
    frames = _frames;
    speed = _speed;
    count = 1;

    name = _name;
    level = _level;
    health = _health;
    stamina = _stamina;
}

Character::Character(const string _path, int _frames, int _speed)
{
    //const char* file = ((_folder + "/" + _action + "/" + _action + "_" + to_string(1) + ".png").c_str());
    string filename = _path+"/"+"1.png";
    const char* file = filename.c_str();
    characterTexture = Textures::LoadTexture(file);
 

    path = _path;
    frames = _frames;
    speed = _speed;
    count = 1;
}
*/

Character::~Character()
{
    SDL_DestroyTexture(characterTexture);
}

// MAYBE MAKE UPDATE A VIRTUAL FUNCTION 

void Character::Update() 
{
    
    // implement movement animation
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

void Character::Clean()
{
    SDL_DestroyTexture(characterTexture);
}
// Setters 
void Character::SetTexture(const char* texture)
{
    characterTexture = Textures::LoadTexture(texture);
}
void Character::SetSourceRect(SDL_Rect src)
{
    srcRect = src;
}
void Character::SetDestinationRect(SDL_Rect dest)
{
    destRect = dest;
}
void Character::SetXPos(int x)
{
    xpos = x;
}
void Character::SetYPos(int y)
{
    ypos = y;
}


void Character::SetPath(string _path)
{
    path = _path;
}
void Character::SetFrames(int _frames)
{
    frames = _frames;
}
void Character::SetSpeed(int _speed)
{
    speed = _speed;
}
void Character::SetCount(int _count)
{
    count = _count;
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
void Character::SetStamina(int _stamina)
{
    stamina = _stamina;
}

// Getters
string Character::GetPath()
{
    return path;
}
int Character::GetFrames()
{
    return frames;
}
int Character::GetSpeed()
{
    return speed;
}
int Character::GetCount()
{
    return count;
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
int Character::GetStamina()
{
    return stamina;
}

// Actions
void Character::Idle(const string _path, int _frames, int _speed)
{    
    const char* file = _path.c_str();
    characterTexture = Textures::LoadTexture(file);
    frames = _frames;
    speed = _speed;
    count = 1;
   
}
void Character::TakeDamage(const string _path, int _frames, int _speed)
{

}
void Character::Defend(const string _path, int _frames, int _speed)
{

}
void Character::Death(const string _path, int _frames, int _speed)
{

}

// Save/Load data 
void Character::SaveProgress()
{

}
void Character::LoadProgress(string file)
{

}