LIBDIRS = $(wildcard /lib/*)
INCLUDES = $(addprefix -I, $(LIBDIRS)



game: 
	clang++ -std=c++11 src/*.cpp -o play -I include/ -L lib/ -l SDL2-2.0.0 -l SDL2_image -l SDL2_ttf


#clang++ -std=c++11 src/*.cpp -o play -I include/SDL2 -L lib/SDL2 -l SDL2-2.0.0 -l SDL2_image
