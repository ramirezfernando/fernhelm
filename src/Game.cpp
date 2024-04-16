#include "Game.h"
#include "Textures.h"
#include "Character.h"
#include "FireKnight.h"
#include "GroundMonk.h"
#include "WaterPriestess.h"
#include "Background.h"
#include<unistd.h>

Background* forest;
Background* textBox;
Character* player;
Character* enemy;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool isPlayer1Turn = true;
bool isPlayer2Turn = false;

// Helper functions to handle events based on the text box that is displayed
void handleMenuEvents(SDL_Event &event, Background *textBox);
void handleAttackEvents(SDL_Event &event, Background* textBox, Character *player, Character *enemy);
void handleStatsEvents(SDL_Event &event, Background* textBox, Character *player);
void handleRunEvents(SDL_Event &event, Background* textBox, Game* game);
void handleSaveEvents(SDL_Event &event, Background* textBox, Character *player);

CharacterInfo* Game::Menu() 
{
    CharacterInfo* info = new CharacterInfo[2];

    string fileName;
    int option, characterChoice, enemyChoice;
    bool valid = false, validPlayer1Choice = false, validPlayer2Choice = false, validFile = false, isPlayer1LoadedGame = false, isPlayer2LoadedGame = false;

    while(!valid) {
        cout << "Welcome to Fernhelm..." << endl;
        cout << "> Enter '1' to choose your character" << endl;
        cout << "> Enter '0' to quit" << endl;
        cin >> option;

        if (option == 1 || option == 0) {
            valid = true;
            break;
        } 
        else {
            cout << "Invalid input!" << endl;
        }
    }

    switch(option) {
        case 0:
            exit(0);
            break;
        case 1:
            while (!validPlayer1Choice) {
                cout << "[Player 1] Choose your character" << endl;
                cout << "> Enter '1' to choose Fire Knight" << endl;
                cout << "> Enter '2' to choose Water Priestess" << endl;
                cout << "> Enter '3' to choose Ground Monk" << endl;
                cout << "> Enter '4' to load character data" << endl;

                cin >> characterChoice;
                switch(characterChoice) {
                    case 1:
                        info[0].characterChosen =  "FireKnight";
                        validPlayer1Choice = true;
                        break;
                    case 2:
                        info[0].characterChosen =  "WaterPriestess";
                        validPlayer1Choice = true;
                        break;
                    case 3:
                        info[0].characterChosen =  "GroundMonk";
                        validPlayer1Choice = true;
                        break;
                    case 4:
                        while (!validFile) {
                            cout << "[Player 1] Enter character data file name:" << endl;
                            cin >> fileName;                            
                            try {
                                info[0] = player->LoadProgress(fileName);
                                cout << "Successfully loaded game" << endl;
                                isPlayer1LoadedGame = true;
                                validFile = true;
                                validPlayer1Choice = true;
                            }
                            catch(invalid_argument& arg) {
                                cout << arg.what() << endl;
                        }
                        break;
                    default:
                        validPlayer1Choice = false;
                        break;
                }
            }
            // Stores Player 1 info thats gonna be used to initialize your character into a struct
            if (!isPlayer1LoadedGame) {
                cout << "[Player 1] Enter your name: ";
                cin >> info[0].userName;
                info[0]._level = 1;
                info[0]._health = 100;
                info[0]._energy = 100;
            }

            // reset validFile to false for Player 2
            validFile = false;

            while (!validPlayer2Choice) {
                cout << "[Player 2] Choose your character" << endl;
                cout << "> Enter '1' to choose Fire Knight" << endl;
                cout << "> Enter '2' to choose Water Priestess" << endl;
                cout << "> Enter '3' to choose Ground Monk" << endl;
                cout << "> Enter '4' to load character data" << endl;
                cin >> enemyChoice;
                switch(enemyChoice) {
                    case 1:
                        info[1].characterChosen =  "FireKnight";
                        validPlayer2Choice = true;
                        break;
                    case 2:
                        info[1].characterChosen =  "WaterPriestess";
                        validPlayer2Choice = true;
                        break;
                    case 3:
                        info[1].characterChosen =  "GroundMonk";
                        validPlayer2Choice = true;
                        break;
                    case 4:
                        while (!validFile) {
                            cout << "[Player 2] Enter character data file name:" << endl;
                            cin >> fileName;                            
                            try {
                                info[1] = enemy->LoadProgress(fileName);
                                cout << "Successfully loaded game" << endl;
                                isPlayer2LoadedGame = true;
                                validFile = true;
                                validPlayer2Choice = true;
                            }
                            catch(invalid_argument& arg) {
                                cout << arg.what() << endl;
                            }
                        }
                        break;
                    default:
                        validPlayer2Choice = false;
                        break;
                }
            }

            // Stores Player 2 info thats gonna be used to initialize your character into a struct
            if (!isPlayer2LoadedGame) {
                cout << "[Player 2] Enter your name: ";
                cin >> info[1].userName;
                info[1]._level = 1;
                info[1]._health = 100;
                info[1]._energy = 100;
            }

            return info;
        }
    }
}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    // Initializing your character based on the inputs from menu screen
    CharacterInfo* info = Menu();
    // [Player 1] Non loaded game
    if (info[0]._level == 1) {
        if (info[0].characterChosen == "FireKnight") {
        player = new FireKnight(false, info[0].userName);
        }
        else if (info[0].characterChosen == "WaterPriestess") {
            player = new WaterPriestess(false, info[0].userName);
        }
        else if (info[0].characterChosen == "GroundMonk") {
            player = new GroundMonk(false, info[0].userName);
        }
        player->setCharacterType(info[0].characterChosen);
    } 
    // [Player 1] Loaded game
    else {
        if (info[0].characterChosen == "FireKnight") {
            player = new FireKnight(false, info[0].userName, info[0]._level, info[0]._health, info[0]._energy); 
        }
        else if (info[0].characterChosen == "WaterPriestess") {
            player = new WaterPriestess(false, info[0].userName, info[0]._level, info[0]._health, info[0]._energy); 
        }
        else if (info[0].characterChosen == "GroundMonk") {
            player = new GroundMonk(false, info[0].userName, info[0]._level, info[0]._health, info[0]._energy); 
        } 
        player->setCharacterType(info[0].characterChosen);
    }

    // [Player 2] Non loaded game
    if (info[1]._level == 1) {
        if (info[1].characterChosen == "FireKnight") {
        enemy = new FireKnight(true, info[1].userName);
        }
        else if (info[1].characterChosen == "WaterPriestess") {
            enemy = new WaterPriestess(true, info[1].userName);
        }
        else if (info[1].characterChosen == "GroundMonk") {
            enemy = new GroundMonk(true, info[1].userName);
        }
        enemy->setCharacterType(info[1].characterChosen);
    } 
    // [Player 2] Loaded game
    else {
        if (info[1].characterChosen == "FireKnight") {
            enemy = new FireKnight(true, info[1].userName, info[1]._level, info[1]._health, info[1]._energy); 
        }
        else if (info[1].characterChosen == "WaterPriestess") {
            enemy = new WaterPriestess(true, info[1].userName, info[1]._level, info[1]._health, info[1]._energy); 
        }
        else if (info[1].characterChosen == "GroundMonk") {
            enemy = new GroundMonk(true, info[1].userName, info[1]._level, info[1]._health, info[1]._energy); 
        } 
        enemy->setCharacterType(info[1].characterChosen);
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

    // Initializing the background, text box, and enemy in order to display on screen
    forest = new Background("assets/Backgrounds/forest.png", 0, 0, false);
    textBox = new Background("assets/TextBoxes/Main.png", 40, 490, true);
}
void Game::HandleEvents()
{
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;        
            break;
        case SDL_KEYDOWN:
            if (isPlayer1Turn) {
                cout << "It's Player 1's turn" << endl;
                if (textBox->GetPath() == "assets/TextBoxes/Main.png") {
                    handleMenuEvents(event, textBox);
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Attack.png") {
                    handleAttackEvents(event, textBox, player, enemy);
                    isPlayer1Turn = false;
                    isPlayer2Turn = true;
                    textBox->SetPath("None");
                    // TODO: add delay before text box is displayed
                    textBox->SetPath("assets/TextBoxes/Main.png");
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Stats.png") {
                    handleStatsEvents(event, textBox, player);
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Run.png") {
                    handleRunEvents(event, textBox, this);
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Save.png") {
                    handleSaveEvents(event, textBox, player);
                }
                
            }
            
            else if (isPlayer2Turn) {
                cout << "It's Player 2's turn" << endl;
                if (textBox->GetPath() == "assets/TextBoxes/Main.png") {
                    handleMenuEvents(event, textBox);
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Attack.png") {
                    handleAttackEvents(event, textBox, enemy, player);
                    isPlayer1Turn = true;
                    isPlayer2Turn = false;
                    textBox->SetPath("None");
                    // TODO: add delay before text box is displayed
                    textBox->SetPath("assets/TextBoxes/Main.png");
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Stats.png") {
                    handleStatsEvents(event, textBox, enemy);
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Run.png") {
                    handleRunEvents(event, textBox, this);
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Save.png") {
                    handleSaveEvents(event, textBox, enemy);
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

    forest->Render();
    textBox->Render();
    player->Render();
    enemy->Render();

    SDL_RenderPresent(renderer); // Double buffering
}
void Game::Clean()
{
    forest->Clean();
    textBox->Clean();
    player->Clean();
    enemy->Clean();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();
    cout << "Game cleaned" << endl;
}
bool Game::Running()
{
    return isRunning;
}
void Game::SetRunning(bool _isRunning)
{
    isRunning = _isRunning;
}
void handleMenuEvents(SDL_Event &event, Background *textBox)
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
// TODO: Fix lag when running two player animations at the same time
void handleAttackEvents(SDL_Event &event, Background *textBox, Character *player, Character *enemy)
{
    switch(event.key.keysym.sym){
        case SDLK_1:
            player->Attack1();
            enemy->TakeDamage(2 * player->GetLevel()); 

            if (enemy->GetHealth() <= 0) { 
                enemy->Death(); 
            }
            player->SetLevel(player->GetLevel() + 1);
            textBox->SetPath("None");
            break;
        case SDLK_2:
            player->Attack2();
            enemy->TakeDamage(4 * player->GetLevel());

            if (enemy->GetHealth() <= 0) { 
                enemy->Death(); 
            }
            player->SetLevel(player->GetLevel() + 1);
            textBox->SetPath("None");
            break;
        case SDLK_3:
            player->Attack3();
            enemy->TakeDamage(8 * player->GetLevel());

            if (enemy->GetHealth() <= 0) { 
                enemy->Death(); 
            }
            player->SetLevel(player->GetLevel() + 2);
            player->SetEnergy(player->GetEnergy() - 4);
            textBox->SetPath("None");
            break;
        case SDLK_4:
            player->Attack4();
            enemy->TakeDamage(10 * player->GetLevel());

            if (enemy->GetHealth() <= 0) { 
                enemy->Death(); 
            }
            player->SetLevel(player->GetLevel() + 3);
            player->SetEnergy(player->GetEnergy() - 8);
            textBox->SetPath("None");
            break;
        default:
            textBox->SetPath("assets/TextBoxes/Main.png"); // if you press any key it will go back to the main text box
            break;
    }
}
void handleStatsEvents(SDL_Event &event, Background *textBox, Character *player)
{
    switch(event.key.keysym.sym){
        case SDLK_1:
            player->PrintStats();
            break;
        default:
            textBox->SetPath("assets/TextBoxes/Main.png");
            break;
    }
}
void handleRunEvents(SDL_Event &event, Background *textBox, Game *game)
{
    switch(event.key.keysym.sym){
        case SDLK_1:
            game->SetRunning(false);
            break;
        case SDLK_2:
            textBox->SetPath("assets/TextBoxes/Main.png");
            break;
        default:
            textBox->SetPath("assets/TextBoxes/Main.png"); // if you press any key it will go back to the main text box
            break;
    }
}
void handleSaveEvents(SDL_Event &event, Background *textBox, Character *player)
{
    cout << "Saving game..." << endl;
    player->SaveProgress(player->getCharacterType());
    cout << "Successfully saved game" << endl;
    switch(event.key.keysym.sym){
        case SDLK_1:
            textBox->SetPath("assets/TextBoxes/Main.png");
            break;
        default:
            textBox->SetPath("assets/TextBoxes/Main.png"); // if you press any key it will go back to the main text box
            break;
    }
}