# COSC1437
Projects for Introduction to Programming (Spring 2022)

# Project 1
![Project 1 pg1](/images/project1Requirements.png)

# Project 2
![Project 2 pg1](/images/project2Requirements1.png)
![Project 2 pg2](/images/project2Requirements2.png)

## Getting Started

### Dependencies

* Package Manager: [Homebrew](https://brew.sh/)
* SDL2
* SDL2_image
* SDL2_ttf

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
