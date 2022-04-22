# WORDLE-
a wordle like game using c
also an attempt at learning SDL

to compile:
1. make sure to include the required SDL header files and libraries (including SDL_Image ones) in folders /include and /lib 
2. also include the .dll files required for SDL2 and SDL2_Image.

for gcc:

g++ -Iinclude -Llib -o WORDLE graphics.c input.c main.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image