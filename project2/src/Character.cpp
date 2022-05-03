#include "Character.h"
#include "Textures.h"

void Character::Update() 
{

    srcRect.h = 220; //200
    srcRect.w = 320; //300
    
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w * 2;

    // implement movement animation
    if (count <= frames ) {
        // conversions because "LoadTexture" takes a "const char*" as input
        // ex: path = "assests/FireKnight/1_atk"
        // then filename would be "assests/FireKnight/1_atk/(count).png"
        string filename = path+"/"+ to_string(count) + ".png";
        const char* file = filename.c_str();
        characterTexture = Textures::LoadTexture(file);
        SDL_Delay(speed);
        count++;
    } 
    // this is to keep animation running infinitely
    /*
    else {
        // count = 1 because all my file names start at 1
        count = 1;
    }
    */
}


void Character::Render()
{
    // if enemy then the image needs to be inverted to face the other player
    if (enemy) {
        Textures::RenderInvertedTexture(characterTexture, srcRect, destRect, SDL_FLIP_HORIZONTAL);
    }
    else {
        SDL_RenderCopy(Game::renderer, characterTexture, &srcRect, &destRect);
    }
    
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
void Character::SetEnemy(bool _enemy)
{
    enemy = _enemy;
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
bool Character::GetEnemy()
{
    return enemy;
}
// Load data 
CharacterInfo Character::LoadProgress(string file)
{
    CharacterInfo info;
    //string character, name, level, health, energy, combinedString;
    ifstream fin("savedData/"+file);
    if (!fin.is_open()) {
        throw invalid_argument("No such file name.");
   }

    while(!fin.eof()) {
        fin >> info.characterChosen;
        fin >> info.userName;
        fin >> info._level;
        fin >> info._health;
        fin >> info._energy;
    }
    
    //combinedString = character + " " + name + " " + level + " " + health + " " + energy; 
    fin.close();
    return info;
}