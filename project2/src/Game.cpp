#include "Game.h"
#include "Textures.h"
#include "Character.h"

Character* player;
Character* enemy;


Game::Game()
{

}
Game::~Game()
{

}
void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen == true)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
    {
        cout << "Initializing" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags); 
        if (window)
        {
            cout << "Window created" << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created" << endl;
        }
        isRunning = true;
    } 
    else 
    {
        isRunning = false;
    }
    // run plaer
    player = new Character("assets/player.png", renderer, 0, 0);
    enemy = new Character("assets/player.png", renderer, 50, 50);

}
void Game::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;        
            break;
        
        default:
            break;
    }

}
void Game::Update()
{
    player->Update();
    enemy->Update();
}
void Game::Render()
{
    SDL_RenderClear(renderer);
    // This is where to add stuff to render, 
    player->Render();
    enemy->Render();
    //
    SDL_RenderPresent(renderer);
}
void Game::Clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}
bool Game::Running()
{
    return isRunning;
}