#include "Game.h"

using namespace std;

#ifndef BACKGROUND_H
#define BACKGROUND_H
// This class is used to handle the background image
class Background
{
    public:
        Background(const char* background, int xpos, int ypos, bool text);
        
        void Update();
        void Render();
        void Clean();

        void SetPath(string );
        string GetPath();

    private:
        SDL_Texture* backgroundTexture;
        SDL_Rect srcRect, destRect;
        int xpos;
        int ypos;
        bool text;
        string path;
};

#endif