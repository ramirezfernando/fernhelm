#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "Game.h"
#include "Character.h"

using namespace std;


int main() {
    Game *game = nullptr;
    game = new Game();
    
    game->init("RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }
    
    game->clean();

    
    return 0;
}