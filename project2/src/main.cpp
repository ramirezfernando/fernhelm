#include <SDL2/SDL.h>
#include <iostream>
#include <string>


#include "Game.h"


using namespace std;


int main(int argc, const char * argv[]) {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;


    Game *game = nullptr;
    game = new Game();
    // Create the window
    game->Init("RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    // Game loop
    while (game->Running())
    {
        frameStart = SDL_GetTicks();
        game->HandleEvents();
        game->Update();
        game->Render();

        // Handles frame rate
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->Clean();

    
    return 0;
}