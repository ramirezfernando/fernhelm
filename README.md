# COSC1437
Projects for Introduction to Programming (Spring 2022)

# Project 1
![Project 1 pg1](/images/project1Requirements.png)

# Project 2
![Project 2 pg1](/images/project2Requirements1.png)
![Project 2 pg2](/images/project2Requirements2.png)
![RPG](/images/rpg.png)

## Getting Started

### Dependencies
The system requirements for running on a Mac are:
* Mac OS X 12.3.1 (not tested on other versions)
* Apple clang version 13.1.6 (if other compiler is used, changed "clang++" to your compiler in Makefile)
* Package Manager: [Homebrew](https://brew.sh/)
* [SDL2](https://www.libsdl.org/)
* [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
* [SDL2_ttf](https://www.libsdl.org/projects/docs/SDL_ttf/SDL_ttf.html)

### Installing

* Git clone https://github.com/ramirezfernando/COSC1437.git
* cd ./project2

* Download Homebrew
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)
```
* Download SDL2 libraries
```
brew install sdl2
brew install sdl2_image
brew install sdl2_ttf
```
* Link the SDL2 libraries to the project
```
ln -s /usr/local/Cellar/sdl2/2.0.20/include/SDL2 ./include/SDL2
ln -s /usr/local/Cellar/sdl2/2.0.20/lib ./lib/SDL2

ln -s /usr/local/Cellar/sdl2_image/2.0.5/include/SDL2 ./include/SDL2_image
ln -s /usr/local/Cellar/sdl2_image/2.0.5/lib ./lib/SDL2_image

ln -s /usr/local/Cellar/sdl2_ttf/2.0.18_1/include/SDL2 ./include/SDL2_ttf
ln -s /usr/local/Cellar/sdl2_ttf/2.0.18_1/lib ./lib/SDL2_ttf
```

### Executing program

* Compile the program into an executable
```
make game
```
* Run the executable
```
./play
```

## Acknowledgments

Special Thanks!
* [Let's Make Games](https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx)
* [Chierit](https://chierit.itch.io/)
* [Forest Background](https://pixeljoint.com/pixelart/120493.htm)
* [SDL2 Help](https://github.com/Twinklebear/TwinklebearDev-Lessons/issues/14)
