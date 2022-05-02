#include "Game.h"
#include "Text.h"
#include "Textures.h"
#include "Character.h"
#include "FireKnight.h"
#include "GroundMonk.h"
#include "WaterPriestess.h"
#include "Background.h"

Background* forest;
Background* textBox;
Character* player;
Character* enemy;
Text* text;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

string Game::Menu() 
{
    string fileName;
    int option, characterChoice;
    bool valid = false, validCharacter = false, validFile = false;

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
            }
        case 2:
            while (!validFile) {
                cout << "Enter character data file name:" << endl;
                cin >> fileName;
                
                // File input for loading character stats such as health, level, stamina
                try {
                    string characterInfo = player->LoadProgress(fileName); // check inside Character.cpp for more info
                    return characterInfo;
                }
                catch(invalid_argument& i) {
                    cout << i.what() << endl;
                }
            }
            
        default:
            cout << "default" << endl;
            break;
    }
}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    string userCharacter = Menu();
    string character = "", name = "", level = "", health = "", energy = "";
    int count = 1;
    if (userCharacter == "FireKnight") {
        player = new FireKnight();
    }
    else if (userCharacter == "WaterPriestess") {
        player = new WaterPriestess();
    }
    else if (userCharacter == "GroundMonk") {
        player = new GroundMonk();
    }
    else {
        // parse userCharacter back into character, name, level, health & energy
        cout << userCharacter << endl;
        for(int i = 0; i < userCharacter.length(); i++) {
            
            if (userCharacter[i] == ' ') {
                count++;
            }
            else if (count == 1) {
                character = character + userCharacter[i];
            }
            else if (count == 2) {
                name = name + userCharacter[i];
            }
            else if (count == 3) {
                level = level + userCharacter[i];
            }
            else if (count == 4) {
                health = health + userCharacter[i];
            }
            else if (count == 5) {
                energy = energy + userCharacter[i];
            }
        }
        /*
        cout << endl;
        cout << character << endl;
        cout << name << endl;
        cout << level << endl;
        cout << health << endl;
        cout << energy << endl;
        cout << endl;
        */
        if (character == "FireKnight") {
            player = new FireKnight(name,stoi(level),stoi(health),stoi(energy)); //stoi: string to int
        }
        else if (character == "WaterPriestess") {
            player = new WaterPriestess(name,stoi(level),stoi(health),stoi(energy)); //stoi: string to int
        }
        else if (character == "GroundMonk") {
            player = new GroundMonk(name,stoi(level),stoi(health),stoi(energy)); //stoi: string to int
        } 
          
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
    // Initializing SDL2_ttf (true type font)
    if (TTF_Init() == -1) {
        cout << "Could not initialize ttf" << endl;
    }
    else 
    {
        cout << "Initializing ttf" << endl;
    }
    forest = new Background("assets/forest.png", 0, 0, false);
    textBox = new Background("assets/TextBoxes/Main.png", 40, 490, true);
    enemy = new FireKnight(true);

    SDL_Color color = { 255, 255, 0};
    text = new Text("assets/Fonts/8bit.ttf", 30, "TESTING", color);


}
void Game::HandleEvents()
{
    bool someoneAlive = true;
    SDL_PollEvent(&event);
    
   
    switch (event.type)
    {
        
        case SDL_QUIT:
            isRunning = false;        
            break;
        case SDL_MOUSEBUTTONDOWN:
            break;

        case SDL_KEYDOWN:
            if (textBox->GetPath() == "assets/TextBoxes/Main.png") 
            {
                switch(event.key.keysym.sym){
                    case SDLK_1:
                        textBox->SetPath("assets/TextBoxes/Attack.png");
                        break;
                    case SDLK_2:
                        textBox->SetPath("assets/TextBoxes/Stats.png");
                        break;
                    case SDLK_3:
                        textBox->SetPath("assets/TextBoxes/Run.png");
                        break;
                    case SDLK_4:
                        textBox->SetPath("assets/TextBoxes/Save.png");
                        break;
                    default:
                        textBox->SetPath("assets/TextBoxes/Main.png");
                        break;
                }
            }
            else if(textBox->GetPath() == "assets/TextBoxes/Attack.png") 
            {
                switch(event.key.keysym.sym){
                    case SDLK_1:
                        player->Attack1();
                        //if (player->GetHealth() <= 0) { player->Death(); }
                        if (enemy->GetHealth() <= 0) { enemy->Death(); }
                        else { enemy->TakeDamage(2 * player->GetLevel()); }
                        break;
                    case SDLK_2:
                        player->Attack2();
                        if (enemy->GetHealth() <= 0) { enemy->Death(); }
                        else { enemy->TakeDamage(4 * player->GetLevel()); }
                        break;
                    case SDLK_3:
                        player->Attack3();
                        if (enemy->GetHealth() <= 0) { enemy->Death(); }
                        else { enemy->TakeDamage(8 * player->GetLevel()); }
                        break;
                    case SDLK_4:
                        player->Attack4();
                        if (enemy->GetHealth() <= 0) { enemy->Death(); }
                        else { enemy->TakeDamage(10 * player->GetLevel()); }
                        break;
                    default:
                        textBox->SetPath("assets/TextBoxes/Main.png");
                        break;
                }
            }
            else if(textBox->GetPath() == "assets/TextBoxes/Stats.png") 
            {
                //SDL_Color color = {255, 0, 0, 255};
                //Text text("assets/Fonts/8bit.ttf", 50, "Pooop", color);
                switch(event.key.keysym.sym){
                    case SDLK_1:

                        text->Display(0,0);
                        break;
                    default:
                        textBox->SetPath("assets/TextBoxes/Main.png");
                        break;
                }
            }
            else if(textBox->GetPath() == "assets/TextBoxes/Run.png") 
            {
                switch(event.key.keysym.sym){
                    case SDLK_1:
                        isRunning = false;
                        break;
                    case SDLK_2:
                        textBox->SetPath("assets/TextBoxes/Main.png");
                        break;
                    default:
                        textBox->SetPath("assets/TextBoxes/Main.png");
                        break;
                }
            }
            else if(textBox->GetPath() == "assets/TextBoxes/Save.png") 
            {
                switch(event.key.keysym.sym){
                    case SDLK_1:
                        textBox->SetPath("assets/TextBoxes/Main.png");
                        break;
                    default:
                        textBox->SetPath("assets/TextBoxes/Main.png");
                        break;
                }
            }
            
        }
    
}
void Game::Update()
{
    forest->Update();
    textBox->Update();
    player->Update();
    enemy->Update();
}
void Game::Render()
{
    SDL_RenderClear(renderer);
    // This is where to add stuff to render, 
    forest->Render();
    textBox->Render();
    player->Render();
    enemy->Render();
    //
    SDL_RenderPresent(renderer);
}
void Game::Clean()
{
    // add destructors for character and background
    forest->Clean();
    textBox->Clean();
    player->Clean();
    enemy->Clean();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    cout << "Game cleaned" << endl;
}
bool Game::Running()
{
    return isRunning;
}