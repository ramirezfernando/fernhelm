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
string characterType;


CharacterInfo Game::Menu() 
{
    CharacterInfo info;

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
                        info.characterChosen =  "FireKnight";
                        validCharacter = true;
                        break;
                    case 2:
                        info.characterChosen =  "WaterPriestess";
                        validCharacter = true;
                        break;
                    case 3:
                        info.characterChosen =  "GroundMonk";
                        validCharacter = true;
                        break;
            }
            cout << "Enter your name: ";
            cin >> info.userName;
            info._level = 1;
            info._health = 100;
            info._energy = 100;
            return info;


            }
        case 2:
            while (!validFile) {
                cout << "Enter character data file name:" << endl;
                cin >> fileName;
                
                // File input for loading character stats such as health, level, stamina
                try {
                    CharacterInfo ci = player->LoadProgress(fileName); // check inside Character.cpp for more info
                    return ci;
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
    CharacterInfo userCharacter = Menu();
    string character = "", name = "", level = "", health = "", energy = "";
    int count = 1;
    
    if (userCharacter.characterChosen == "FireKnight") {
        player = new FireKnight(userCharacter.userName);
        characterType = "FireKnight";
    }
    else if (userCharacter.characterChosen == "WaterPriestess") {
        player = new WaterPriestess(userCharacter.userName);
        characterType = "WaterPriestess";
    }
    else if (userCharacter.characterChosen == "GroundMonk") {
        player = new GroundMonk(userCharacter.userName);
        characterType = "GroundMonk";
    }
    else {
        
        
        if (userCharacter.characterChosen == "FireKnight") {
            player = new FireKnight(userCharacter.userName, userCharacter._level, userCharacter._health, userCharacter._energy); 
            characterType = "FireKnight";
        }
        else if (userCharacter.characterChosen == "WaterPriestess") {
            player = new WaterPriestess(userCharacter.userName, userCharacter._level, userCharacter._health, userCharacter._energy); 
            characterType = "WaterPriestess";
        }
        else if (userCharacter.characterChosen == "GroundMonk") {
            player = new GroundMonk(userCharacter.userName, userCharacter._level, userCharacter._health, userCharacter._energy); 
            characterType = "GroundMonk";
        } 
          
    }
    


    int flags = 0;
    if (fullscreen == true)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    // Initializing SDL2 window
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
    // Initializing SDL2_ttf (true type font) meant to display strings on screen but doesn't work right now.
    if (TTF_Init() == -1) {
        cout << "Could not initialize ttf" << endl;
    }
    else 
    {
        cout << "Initializing TTF" << endl;
    }

    forest = new Background("assets/forest.png", 0, 0, false);
    textBox = new Background("assets/TextBoxes/Main.png", 40, 490, true);
    enemy = new FireKnight(true); // bool is to check if an enemy, then invert their image

    // meant for SDL2_ttf but doesn't work right now
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
                        player->Attack1(); // player attack animation
                        if (enemy->GetHealth() <= 0) { 
                            enemy->Death(); 
                        }
                        else { 
                            enemy->SetHealth( (enemy->GetHealth()) - (2 * player->GetLevel()));
                        }
                        player->SetLevel(player->GetLevel() + 1); // increases level
                        player->SetEnergy(player->GetEnergy() - 4);
                        textBox->SetPath("None");
                        break;
                    case SDLK_2:
                        player->Attack2();
                        if (enemy->GetHealth() <= 0) { 
                            enemy->Death(); 
                        }
                        else { 
                            enemy->SetHealth( (enemy->GetHealth()) - (4 * player->GetLevel()));
                        }
                        player->SetLevel(player->GetLevel() + 1); // increases level
                        textBox->SetPath("None");
                        break;
                    case SDLK_3:
                        player->Attack3();
                        if (enemy->GetHealth() <= 0) { 
                            enemy->Death(); 
                        }
                        else { 
                            enemy->SetHealth( (enemy->GetHealth()) - (8 * player->GetLevel()));
                        }
                        player->SetLevel(player->GetLevel() + 1); // increases level
                        player->SetEnergy(player->GetEnergy() - 4);
                        textBox->SetPath("None");
                        break;
                    case SDLK_4:
                        player->Attack4();
                        if (enemy->GetHealth() <= 0) { 
                            enemy->Death(); 
                        }
                        else { 
                            enemy->SetHealth( (enemy->GetHealth()) - (10 * player->GetLevel()));
                        }
                        player->SetLevel(player->GetLevel() + 1); // increases level
                        player->SetEnergy(player->GetEnergy() - 8);
                        textBox->SetPath("None");
                        break;
                    default:
                        textBox->SetPath("assets/TextBoxes/Main.png");
                        break;
                }
            }
            else if(textBox->GetPath() == "assets/TextBoxes/Stats.png") 
            {
                switch(event.key.keysym.sym){
                    case SDLK_1:
                        player->PrintStats();
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
                player->SaveProgress(characterType); // saves data and passes characterType as argument which can be "FireKnight", "WaterPriestess", or "GroundMonk"
                switch(event.key.keysym.sym){
                    case SDLK_1:
                        textBox->SetPath("assets/TextBoxes/Main.png");
                        break;
                    default:
                        textBox->SetPath("assets/TextBoxes/Main.png");
                        break;
                }
            }
            else if(textBox->GetPath() == "None") {
                switch(event.key.keysym.sym){
                    case SDLK_1:
                        enemy->Attack1();
                        if (player->GetHealth() <= 0) { player->Death(); }
                        else { player->SetHealth( (player->GetHealth()) - (2 * enemy->GetLevel())); }
                        break;
                    case SDLK_2:
                        enemy->Attack2();
                        if (player->GetHealth() <= 0) { player->Death(); }
                        else { player->SetHealth( (player->GetHealth()) - (4 * enemy->GetLevel())); }
                        break;
                    case SDLK_3:
                        enemy->Attack3();
                        if (player->GetHealth() <= 0) { player->Death(); }
                        else { player->SetHealth( (player->GetHealth()) - (6 * enemy->GetLevel())); }
                        break;
                    case SDLK_4:
                        enemy->Attack4();
                        if (player->GetHealth() <= 0) { player->Death(); }
                        else { player->SetHealth( (player->GetHealth()) - (8 * enemy->GetLevel())); }
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