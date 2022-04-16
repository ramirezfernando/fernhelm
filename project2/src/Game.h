#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>
using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    ~Game();

    void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool Running();
    // creates a static renderer without the need of having multiple renderers
    static SDL_Renderer* renderer;
    static SDL_Event event;
private:
    bool isRunning;
    SDL_Window *window;
};

#endif