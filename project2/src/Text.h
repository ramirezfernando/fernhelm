#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Game.h" // to use Game::renderer in LoadFont
#ifndef TEXT_H
#define TEXT_H

using namespace std;
// This class is meant to render strings on screen but does not work at the moment
class Text
{
    public:
        Text(const string &fontPath, int fontSize, const string &message, SDL_Color &color);
        void Display(int x, int y);
        static SDL_Texture *LoadFont(const string &fontPath, int fontSize, const string &message, SDL_Color &color);

    private:
        SDL_Texture* textTexture;
        SDL_Rect textRect;
};

#endif