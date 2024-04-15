#include "Game.h"
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
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
string characterType;


CharacterInfo Game::Menu() 
{
    CharacterInfo info;

    string fileName;
    int option, characterChoice, enemyChoice;
    bool valid = false, validCharacter = false, validEnemy = false, validFile = false;

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
                // Possibly do a try catch handling if the cin isn't an integer
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
                    default:
                        validCharacter = false;
                        break;
                }
            }
            // Stores info thats gonna be used to initialize your character into a struct
            cout << "Enter your name: ";
            cin >> info.userName;
            info._level = 1;
            info._health = 100;
            info._energy = 100;

            while (!validEnemy) {
                cout << "+------------------------+" << endl
                    <<  "| Choose Enemy Character |" << endl
                    <<  "+------------------------+" << endl
                    <<  "|  (1) Fire Knight       |" << endl
                    <<  "|  (2) Water Priestess   |" << endl
                    <<  "|  (3) Ground Monk       |" << endl
                    <<  "+------------------------+"<< endl;
                cout << "Enter 1, 2 or 3" << endl;
                cin >> enemyChoice;
                switch(enemyChoice) {
                    case 1:
                        enemy = new FireKnight(true); // bool is to check if an enemy, then invert their image
                        validEnemy = true;
                        break;
                    case 2:
                        enemy = new WaterPriestess(true); // bool is to check if an enemy, then invert their image
                        validEnemy = true;
                        break;
                    case 3:
                        enemy = new GroundMonk(true); // bool is to check if an enemy, then invert their image
                        validEnemy = true;
                        break;
                    default:
                        validEnemy = false;
                        break;
                }
            }
            return info;
        
        case 2:
            while (!validFile) {
                cout << "Enter character data file name:" << endl;
                cin >> fileName;
                
                // File input for loading character stats such as health, level, stamina
                try {
                    info = player->LoadProgress(fileName); // check inside Character.cpp for more info
                    validFile = true;
                    //return info;
                }
                catch(invalid_argument& arg) {
                    cout << arg.what() << endl;
                }
            }
            while (!validEnemy) {
                cout << "+------------------------+" << endl
                    <<  "| Choose Enemy Character |" << endl
                    <<  "+------------------------+" << endl
                    <<  "|  (1) Fire Knight       |" << endl
                    <<  "|  (2) Water Priestess   |" << endl
                    <<  "|  (3) Ground Monk       |" << endl
                    <<  "+------------------------+"<< endl;
                cout << "Enter 1, 2 or 3" << endl;
                cin >> enemyChoice;
                switch(enemyChoice) {
                    case 1:
                        enemy = new FireKnight(true); // bool is to check if an enemy, then invert their image
                        validEnemy = true;
                        break;
                    case 2:
                        enemy = new WaterPriestess(true); // bool is to check if an enemy, then invert their image
                        validEnemy = true;
                        break;
                    case 3:
                        enemy = new GroundMonk(true); // bool is to check if an enemy, then invert their image
                        validEnemy = true;
                        break;
                }
            }
            return info;
    
            
        default:
            cout << "default" << endl;
            break;
    }
}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    // Initializing your character based on the inputs from menu screen
    CharacterInfo userCharacter = Menu();
    // FOR NON SAVED DATA FILES (1) Choose Character
    if (userCharacter.characterChosen == "FireKnight" && userCharacter._level == 1) {
        player = new FireKnight(userCharacter.userName);
        characterType = "FireKnight";
    }
    else if (userCharacter.characterChosen == "WaterPriestess" && userCharacter._level == 1) {
        player = new WaterPriestess(userCharacter.userName);
        characterType = "WaterPriestess";
    }
    else if (userCharacter.characterChosen == "GroundMonk" && userCharacter._level == 1) {
        player = new GroundMonk(userCharacter.userName);
        characterType = "GroundMonk";
    }

    // FOR SAVED DATA FILES, USE OVERLOADED CONSTRUCTORS (2) Load Character Data
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

    //player->PrintStats();
    //cout << player->GetLevel() << endl;

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
    //enemy = new FireKnight(true); // bool is to check if an enemy, then invert their image
}
void Game::HandleEvents()
{
    SDL_PollEvent(&event);
    
    switch (event.type)
    {
        // if you click the close window button, stops running and cleans memory
        case SDL_QUIT:
            isRunning = false;        
            break;
        case SDL_MOUSEBUTTONDOWN:
            break;

        // if you click a button on the keyboard, the program will go down this path
        case SDL_KEYDOWN:
            // if the textBox is on the main screen
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
            // if the textBox is on the attack screen
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
                        player->SetLevel(player->GetLevel() + 2); // increases level
                        player->SetEnergy(player->GetEnergy() - 4); // decrease energy when using special attacks
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
                        player->SetLevel(player->GetLevel() + 3); // increases level
                        player->SetEnergy(player->GetEnergy() - 8); // decrease energy when using special attacks
                        textBox->SetPath("None");
                        break;
                    default:
                        textBox->SetPath("assets/TextBoxes/Main.png"); // if you press any key it will go back to the main text box
                        break;
                }
            }
            // if the textBox is on the stats screen
            else if(textBox->GetPath() == "assets/TextBoxes/Stats.png") 
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
                        textBox->SetPath("assets/TextBoxes/Main.png"); // if you press any key it will go back to the main text box
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
                        textBox->SetPath("assets/TextBoxes/Main.png"); // if you press any key it will go back to the main text box
                        break;
                }
            }
            // when its the enemies turn
            else if(textBox->GetPath() == "None") {
                switch(event.key.keysym.sym){
                    case SDLK_1:
                        enemy->Attack1(); // player attack animation
                        if (player->GetHealth() <= 0) { 
                            player->Death(); 
                        }
                        else { 
                            player->SetHealth( (player->GetHealth()) - (2 * enemy->GetLevel()));
                        }
                        enemy->SetLevel(enemy->GetLevel() + 1); // increases level
                        break;
                    case SDLK_2:
                        enemy->Attack2(); // player attack animation
                        if (player->GetHealth() <= 0) { 
                            player->Death(); 
                        }
                        else { 
                            player->SetHealth( (player->GetHealth()) - (4 * enemy->GetLevel()));
                        }
                        enemy->SetLevel(enemy->GetLevel() + 1); // increases level
                        break;
                    case SDLK_3:
                        enemy->Attack3(); // player attack animation
                        if (player->GetHealth() <= 0) { 
                            player->Death(); 
                        }
                        else { 
                            player->SetHealth( (player->GetHealth()) - (8 * enemy->GetLevel()));
                        }
                        enemy->SetLevel(enemy->GetLevel() + 1); // increases level
                        enemy->SetEnergy(enemy->GetEnergy() - 4); // decrease energy when using special attacks
                        break;
                    case SDLK_4:
                        enemy->Attack4(); // player attack animation
                        if (player->GetHealth() <= 0) { 
                            player->Death(); 
                        }
                        else { 
                            player->SetHealth( (player->GetHealth()) - (10 * enemy->GetLevel()));
                        }
                        enemy->SetLevel(enemy->GetLevel() + 1); // increases level
                        enemy->SetEnergy(enemy->GetEnergy() - 8); // decrease energy when using special attacks
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
    cout << "Game cleaned" << endl;
}
bool Game::Running()
{
    return isRunning;
}