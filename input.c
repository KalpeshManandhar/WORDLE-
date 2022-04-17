#include "input.h"
#include "header.h"

int gameRun = 1;
char guessword[] = "     ";

void keyInput (SDL_Event* event, int *charNo){
    switch (event->key.keysym.sym)
    {
    case SDLK_a:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'a';
            (*charNo)++;
        }
        break;
    }
    case SDLK_b:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'b';
            (*charNo)++;
        }
        break;
    }
    case SDLK_c:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'c';
            (*charNo)++;
        }
        break;
    }
    case SDLK_d:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'd';
            (*charNo)++;
        }
        break;
    }
    case SDLK_e:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'e';
            (*charNo)++;
        }
        break;
    }
    case SDLK_f:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'f';
            (*charNo)++;
        }
        break;
    }
    case SDLK_g:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'g';
            (*charNo)++;
        }
        break;
    }
    case SDLK_h:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'h';
            (*charNo)++;
        }
        break;
    }
    case SDLK_i:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'i';
            (*charNo)++;
        }
        break;
    }
    case SDLK_j:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'j';
            (*charNo)++;
        }
        break;
    }
    case SDLK_k:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'k';
            (*charNo)++;
        }
        break;
    }
    case SDLK_l:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'l';
            (*charNo)++;
        }
        break;
    }
    case SDLK_m:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'm';
            (*charNo)++;
        }
        break;
    }
    case SDLK_n:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'n';
            (*charNo)++;
        }
        break;
    }
    case SDLK_o:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'o';
            (*charNo)++;
        }
        break;
    }
    case SDLK_p:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'p';
            (*charNo)++;
        }
        break;
    }
    case SDLK_q:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'q';
            (*charNo)++;
        }
        break;
    }
    case SDLK_r:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'r';
            (*charNo)++;
        }
        break;
    }
    case SDLK_s:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 's';
            (*charNo)++;
        }
        break;
    }
    case SDLK_t:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 't';
            (*charNo)++;
        }
        break;
    }
    case SDLK_u:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'u';
            (*charNo)++;
        }
        break;
    }
    case SDLK_v:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'v';
            (*charNo)++;
        }
        break;
    }
    case SDLK_w:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'w';
            (*charNo)++;
        }
        break;
    }
    case SDLK_x:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'x';
            (*charNo)++;
        }
        break;
    }
    case SDLK_y:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'y';
            (*charNo)++;
        }
        break;
    }
    case SDLK_z:{
        if ((*charNo)<5){
            guesses[guessNo-1][*charNo] = 'z';
            (*charNo)++;
        }
        break;
    }
    case SDLK_RETURN:  //enter key
    {
        if ((*charNo)==5){
            (*charNo)=0;
            guesses[guessNo][5] = '\0';
            strcpy(guessWord, guesses[guessNo]);
            printf("%s", guessWord);
            switch(checkWord())
            {
                case CORRECT:   {
                    // printf("CONGRATS YOU WON!");
                    gameRun = GAME_END_WIN;
                    break;
                }
                case WRONG:
                    break;
                case GAME_END_LOSE:
                    gameRun = GAME_END_LOSE;
                    break;
            }
        }
        break;
    }
    case SDLK_BACKSPACE:{
        if ((*charNo)>=0){
            (*charNo)--;
            guesses[guessNo-1][*charNo] = '\0';
        }
        break;
    }
    
    default:
        break;
    }
}
