#include "Game.h"

#include "Textures.h"
#include "Character.h"
#include "FireKnight.h"
#include "GroundMonk.h"
#include "WaterPriestess.h"
#include "Background.h"

Background* forest;
Character* player;


// we haven't initialized SDL yet
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

string Game::Menu() 
{
    string fileName;
    int option, characterChoice;
    bool valid = false, validCharacter = false, validFile;
    while(!valid) {
        cout << "+-------------------------+"<< endl 
            <<  "|      Elements RPG       |"<< endl
            <<  "+-------------------------+"<< endl
            <<  "| (1) Choose Character    |"<< endl
            <<  "| (2) Load Character Data |"<< endl
            <<  "+-------------------------+"<< endl;
        cout << "Enter 1 or 2" << endl;
        cin >> option;
        if (option == 1 || option == 2) {
            valid = true;
            break;
        }
    }

    switch(option) {
        case 1:
            while (!validCharacter) {
            cout << "+---------------------+" << endl
                <<  "|  Choose Character   |" << endl
                <<  "+---------------------+" << endl
                <<  "| (1) Fire Knight     |" << endl
                <<  "| (2) Water Priestess |" << endl
                <<  "| (3) Ground Monk     |" << endl
                <<  "+---------------------+"<< endl;
            cout << "Enter 1, 2 or 3" << endl;
            cin >> characterChoice;
            switch(characterChoice) {
               case 1:
                    return "FireKnight";
                case 2:
                    return "WaterPriestess";
                case 3:
                    return "GroundMonk";
            }

            //break;
            }
        case 2:
            while (!validFile) {
                cout << "Enter character data file name:" << endl;
                cin >> fileName;
                cout << fileName << endl;
                /*
                do file input
                */
            }
            
        default:
            cout << "default" << endl;
            break;
    }
}

SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
   SDL_Color col = {r,g,b,a};
   return col;
}

void Game::RenderHPBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor, SDL_Renderer* renderer) {
   Percent = Percent > 1.f ? 1.f : Percent < 0.f ? 0.f : Percent;
   SDL_Color old;
   SDL_GetRenderDrawColor(renderer, &old.r, &old.g, &old.g, &old.a);
   SDL_Rect bgrect = { x, y, w, h };
   SDL_SetRenderDrawColor(renderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
   SDL_RenderFillRect(renderer, &bgrect);
   SDL_SetRenderDrawColor(renderer, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
   int pw = (int)((float)w * Percent);
   int px = x + (w - pw);
   SDL_Rect fgrect = { px, y, pw, h };
   SDL_RenderFillRect(renderer, &fgrect);
   SDL_SetRenderDrawColor(renderer, old.r, old.g, old.b, old.a);
}


void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    string userCharacter = Menu();
    if (userCharacter == "FireKnight") {
        player = new FireKnight();
    }
    else if (userCharacter == "WaterPriestess") {
        player = new WaterPriestess();
    }
    else {
        player = new GroundMonk();
    }


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

    forest = new Background("assets/forest.png", 0, 0);
    //RenderHPBar(0, 0, 200, 200, 0.75, color(124, 177, 82, 1), color(124, 177, 82, 1), renderer);

}
void Game::HandleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;        
            break;
        case SDL_MOUSEBUTTONDOWN:
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_1:
                    cout << "1" << endl;
                    player->Attack1();
                    break;
                case SDLK_2:
                    cout << "2" << endl;
                    player->Attack2();
                    break;
                case SDLK_3:
                    cout << "3" << endl;
                    player->Attack3();
                    break;
                case SDLK_4:
                    cout << "4" << endl;
                    player->Attack4();
                    break;
                default:
                    break;
                }
        default:
            break;
    }

}
void Game::Update()
{
    forest->Update();
    player->Update();
    //enemy->Update();
}
void Game::Render()
{
    SDL_RenderClear(renderer);
    // This is where to add stuff to render, 
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
    forest->~Background();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}
bool Game::Running()
{
    return isRunning;
}