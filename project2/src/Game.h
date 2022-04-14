#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif