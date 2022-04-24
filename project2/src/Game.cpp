#include "Game.h"
#include "Textures.h"
#include "Character.h"
#include "FireKnight.h"
#include "GroundMonk.h"
#include "WaterPriestess.h"
#include "Background.h"

Background* roster;
Background* forest;
FireKnight* player;
//GroundMonk* player;

// we haven't initialized SDL yet
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;


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
    // Choose your character screen

    forest = new Background("assets/forest.png", 0, 0);
    player = new FireKnight();
    roster = new Background("assets/roster.png", 0, 0);

    //forest = new Background("assets/forest.png", 0, 0);

}
void Game::HandleEvents()
{
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;        
            break;
        case SDL_MOUSEBUTTONDOWN: // && click in a certain box, testing right now
            //delete roster;
            //player = GroundMonk("assets/GroundMonk/idle", 6, 100, -80, 20, "Hey", 1, 100, 100);


        default:
            break;
    }

}
void Game::Update()
{
    roster->Update();
    forest->Update();
    player->Update();
    //enemy->Update();
}
void Game::Render()
{
    SDL_RenderClear(renderer);
    // This is where to add stuff to render, 
    roster->Render();
    forest->Render();
    player->Render();
    //enemy->Render();
    //
    SDL_RenderPresent(renderer);
}
void Game::Clean()
{
    // add destructors for character and background
    player->Clean();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}
bool Game::Running()
{
    return isRunning;
}