# Turn-Based Role-Playing Game 
A 2D turn-based battle game made using C++ and SDL2

![RPG](/images/rpg.png)

## Getting Started

### Dependencies
The system requirements for running on a Mac are:
* Compiler: [Clang](https://clang.llvm.org/)
  * If another compiler is used, update the Makefile compiler to your compiler
* Package Manager: [Homebrew](https://brew.sh/)
* [SDL2](https://www.libsdl.org/)
* [SDL2_image](https://www.libsdl.org/projects/SDL_image/)

### Installation

1. Clone the repo
    ```sh
    git clone https://github.com/ramirezfernando/turn-based-rpg.git
    ```
2. Download Homebrew
    ```sh
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)
    ```
3. Download SDL2 libraries
   ```sh
    brew install sdl2
    brew install sdl2_image
   ```
4. Link the SDL2 libraries to the project
    ```sh
    ln -s /usr/local/Cellar/sdl2/2.0.20/include/SDL2 ./include/SDL2
    ln -s /usr/local/Cellar/sdl2/2.0.20/lib ./lib/SDL2
    
    ln -s /usr/local/Cellar/sdl2_image/2.0.5/include/SDL2 ./include/SDL2_image
    ln -s /usr/local/Cellar/sdl2_image/2.0.5/lib ./lib/SDL2_image
    ```

### Executing program

1. Compile the program into an executable
```
make game
```
2. Run the executable
```
./play
```

## Acknowledgments

Special Thanks!
* [Let's Make Games](https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx)
* [Chierit](https://chierit.itch.io/)
* [Forest Background](https://pixeljoint.com/pixelart/120493.htm)
* [SDL2 Help](https://github.com/Twinklebear/TwinklebearDev-Lessons/issues/14)
