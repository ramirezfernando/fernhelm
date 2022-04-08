#include <iostream>
//#include <deez>
//#include "SDL2.framework/Headers/SDL.h"
#include <SDL2/SDL.h>

using namespace std;

int main()
{
    
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        cout << "SDL_Init failed with error: " << SDL_GetError() << endl;
        return 1;
    }
    
    cout << "Test" << endl;
    
    return EXIT_SUCCESS;    
}

