game: 
	clang++ -std=c++11 src/*.cpp -o play $(shell pkg-config --cflags --libs sdl2) $(shell pkg-config --libs sdl2_image)