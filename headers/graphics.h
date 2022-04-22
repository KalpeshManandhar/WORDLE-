#pragma once
#include "input.h"
#include "header.h"

void closeEverything(SDL_Texture* texture, SDL_Renderer *renderer, SDL_Window *window);
void drawBoxes(SDL_Renderer *renderer);
void changeColor(SDL_Renderer *renderer, conditions *cond, int row);
void srcPosCharTexture(SDL_Rect * src, char alphabet);
void displayCharacters(SDL_Texture * alphaTexture, SDL_Renderer * renderer);
int gameLoop(int argc, char **argv);