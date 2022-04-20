#include "header.h"
#include "graphics.h"
#include "input.h"


#define FPS 60
#define FRAME_DELAY 1000/FPS

#define WIN_WIDTH 540// 30|80|20|80|20|80|20|80|20|80|30  
#define WIN_HEIGHT 830  // 540 + 40+ 60+ 20 +60 +20 +60 +20+60+30

typedef struct {
    Uint8 r, g, b;
}color;
const color green = {0, 210, 0};
const color orange = {210, 150, 20};
const color grey = {100, 100, 100};  

conditions previous[6][5]; // ={{DEF, DEF,DEF,DEF,DEF},{DEF, DEF,DEF,DEF,DEF},{DEF, DEF,DEF,DEF,DEF},{DEF, DEF,DEF,DEF,DEF},{DEF, DEF,DEF,DEF,DEF},{DEF, DEF,DEF,DEF,DEF}};

void closeEverything(SDL_Texture* texture, SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void drawBoxes(SDL_Renderer *renderer)
{
    int i,j;
    SDL_Rect box;
    box.h = 80;
    box.w = 80;
    SDL_SetRenderDrawColor(renderer, grey.r, grey.g, grey.b, 1);
    for (i=0; i<6; i++){
        for (j=0; j<5; j++){
            box.x = 30 + j * 90;
            box.y = 30 + i * 90;
            SDL_RenderFillRect(renderer, &box);
        }
    }
}

void changeColor(SDL_Renderer *renderer, conditions *cond, int row)
{
    int i;
    SDL_Rect box;
    box.h = 80;
    box.w = 80;
    box.y = 30 + (row) * 90;
    for (i=0; i<5; i++){
        switch ((cond+i)->condition)
        {
        case CORRECT_PLACE:
            SDL_SetRenderDrawColor(renderer, green.r, green.g, green.b, 1);
            break;
        case INCORRECT_PLACE:
            SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, 1);
            break;
        case NOT_IN_WORD:
            SDL_SetRenderDrawColor(renderer, grey.r, grey.g, grey.b, 1);
            break;
        default:
            break;
        } 
        box.x = 30 + i * 90;
        SDL_RenderFillRect(renderer, &box);
    }
}

int gameLoop(int argc, char **argv){
    
    if (SDL_Init(SDL_INIT_VIDEO)!=0)
        printf("SDL NO INIT");

    SDL_Window *window;
    window = SDL_CreateWindow("SCUFFED WORDLE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT,  SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    // SDL_Surface *temp;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // temp = SDL_CreateRGBSurface(0, WIN_WIDTH, WIN_HEIGHT, 32, 0, 0, 0,0);
    // texture = SDL_CreateTextureFromSurface(renderer, temp);
    // SDL_FreeSurface(temp);
    SDL_Event event;
    Uint32 frameStart;
    int frameTime;
    int charNo = 0,i;
    
    while(1){  
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            closeEverything(texture, renderer, window);
            break;
        case SDL_KEYDOWN:{
            if (gameRun != GAME_END_WIN && gameRun != GAME_END_LOSE)
                keyInput(&event,&charNo);
        }
        default:
            break;
        }
        
        frameStart = SDL_GetTicks();
        SDL_SetRenderDrawColor(renderer, 31, 31, 31, 0);
        SDL_RenderClear(renderer);
        drawBoxes(renderer);
        for (i=0; i< guessNo; i++)
        {
            changeColor(renderer,previous[i], i);
        }
        SDL_RenderPresent(renderer);
        frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime)
            SDL_Delay(FRAME_DELAY- frameTime);
    }
}

