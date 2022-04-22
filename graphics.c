#include "headers/header.h"
#include "headers/graphics.h"
#include "headers/input.h"
#include <SDL2/SDL_image.h>


#define FPS 60
#define FRAME_DELAY 1000/FPS

#define WIN_WIDTH 500   // 30|80|10|80|10|80|10|80|10|80|30  
#define WIN_HEIGHT 600  // 30|80|10|80|10|80|10|80|10|80|10|80|40

typedef struct {
    Uint8 r, g, b;
}color;
const color green = {0, 210, 0};
const color orange = {210, 150, 20};
const color grey = {80, 80, 80};  

conditions previous[6][5]; 


// clean up everything
void closeEverything(SDL_Texture* texture, SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


// draws the basic 5 x 6 empty boxes
void drawBoxes(SDL_Renderer *renderer)
{
    int i,j;
    SDL_Rect box;
    box.h = 80;
    box.w = 80;
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 1);
    for (i=0; i<6; i++){
        for (j=0; j<5; j++){
            box.x = 30 + j * 90;
            box.y = 30 + i * 90;
            SDL_RenderFillRect(renderer, &box);
        }
    }
}

// changes the color of guess characters 
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

// sets the position of source rectangle for alphabet texture to display a specific alphabet
// the alphabet.png is loaded on a texture and specific parts of it are rendered according 
// to the letter 
void srcPosCharTexture(SDL_Rect * src, char alphabet){
    switch (alphabet)
    {
    case 'a':{
        src->x = 0;
        src->y = 0;
        break;
    }
    case 'b':{
        src->x = 80;
        src->y = 0;
        break;
    }
    case 'c':{
        src->x = 160;
        src->y = 0;
        break;
    }
    case 'd':{
        src->x = 240;
        src->y = 0;
        break;
    }
    case 'e':{
        src->x = 0;
        src->y = 80;
        break;
    }
    case 'f':{
        src->x = 80;
        src->y = 80;
        break;
    }
    case 'g':{
        src->x = 160;
        src->y = 80;
        break;
    }
    case 'h':{
        src->x = 240;
        src->y = 80;
        break;
    }
    case 'i':{
        src->x = 0;
        src->y = 160;
        break;
    }
    case 'j':{
        src->x = 80;
        src->y = 160;
        break;
    }
    case 'k':{
        src->x = 160;
        src->y = 160;
        break;
    }
    case 'l':{
        src->x = 240;
        src->y = 160;
        break;
    }
    case 'm':{
        src->x = 0;
        src->y = 240;
        break;
    }
    case 'n':{
        src->x = 80;
        src->y = 240;
        break;
    }
    case 'o':{
        src->x = 160;
        src->y = 240;
        break;
    }
    case 'p':{
        src->x = 240;
        src->y = 240;
        break;
    }
    case 'q':{
        src->x = 0;
        src->y = 320;
        break;
    }
    case 'r':{
        src->x = 80;
        src->y = 320;
        break;
    }
    case 's':{
        src->x = 160;
        src->y = 320;
        break;
    }
    case 't':{
        src->x = 240;
        src->y = 320;
        break;
    }
    case 'u':{
        src->x = 0;
        src->y = 400;
        break;
    }
    case 'v':{
        src->x = 80;
        src->y = 400;
        break;
    }
    case 'w':{
        src->x = 160;
        src->y = 400;
        break;
    }
    case 'x':{
        src->x = 240;
        src->y = 400;
        break;
    }
    case 'y':{
        src->x = 0;
        src->y = 480;
        break;
    }
    case 'z':{
        src->x = 80;
        src->y = 480;
        break;
    }           
    default:
        break;
    }
}


// displays the letters of current guess and previous guesses 
void displayCharacters(SDL_Texture * alphaTexture, SDL_Renderer * renderer){
    int i,j;
    SDL_Rect src, dest;
    src.h = 80;
    src.w = 80;
    dest.h = 80;
    dest.w = 80;
    // for previous guesses
    for (i=0;i< guessNo;i++){
        for (j=0; j<5; j++){
            srcPosCharTexture(&src, guesses[i][j]);
            dest.x = 30 + j * 90;
            dest.y = 30 + i * 90;
            SDL_RenderCopy(renderer, alphaTexture, &src , &dest);
        }
    }
    // for current guess
    for (j=0; j<5; j++){
        if (guessWord[j] == '\0')
            break;
        srcPosCharTexture(&src, guessWord[j]);
        dest.x = 30 + j * 90;
        dest.y = 30 + guessNo * 90;
        SDL_RenderCopy(renderer, alphaTexture, &src , &dest);
    }

}

// main game loop
int gameLoop(int argc, char **argv){
    
    if (SDL_Init(SDL_INIT_VIDEO)!=0)
        printf("SDL NO INIT");

    SDL_Window *window;
    window = SDL_CreateWindow("SCUFFED WORDLE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT,  SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *temp;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    temp = IMG_Load("data/alphabet.png");
    texture = SDL_CreateTextureFromSurface(renderer, temp);
    SDL_FreeSurface(temp);
    SDL_Event event;
    Uint32 frameStart;
    int frameTime;
    int charNo = 0,i;
    
    while(1){  
        SDL_PollEvent(&event);
        switch (event.type)
        {
        // exit case
        case SDL_QUIT:
            closeEverything(texture, renderer, window);
            break;
        // if input is detected
        case SDL_KEYDOWN:{
            if (gameRun != GAME_END_WIN && gameRun != GAME_END_LOSE)
                keyInput(&event,&charNo);
        }
        default:
            break;
        }
        
        frameStart = SDL_GetTicks();
        // draws background
        SDL_SetRenderDrawColor(renderer, 31, 31, 31, 0);
        SDL_RenderClear(renderer);

        // draws the 5 x 6 boxes
        drawBoxes(renderer);

        // changes color of boxes for previous guesses
        for (i=0; i< guessNo; i++)
        {
            changeColor(renderer,previous[i], i);
        }

        // displays the letters 
        displayCharacters(texture, renderer);

        // renders from backbuffer to present
        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime)
            SDL_Delay(FRAME_DELAY- frameTime);
    }
}

