#pragma once
#include "input.h"
#include "header.h"

void drawBoxes(SDL_Renderer *renderer);
void changeColor(SDL_Renderer *renderer, conditions *cond);
int gameLoop(int argc, char **argv);