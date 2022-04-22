#include "input.h"
#include "header.h"

int gameRun = 1;
char guessWord[6] = "";
char guesses[6][6] = {"", "", "", "", "", ""};

void keyInput (SDL_Event* event, int *charNo){
    int i;
    switch (event->key.keysym.sym)
    {
    case SDLK_a:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'a';
            printf("a");
            (*charNo)++;
        }
        break;
    }
    case SDLK_b:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'b';
            printf("b");
            (*charNo)++;
        }
        break;
    }
    case SDLK_c:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'c';
            printf("c");
            (*charNo)++;
        }
        break;
    }
    case SDLK_d:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'd';
            printf("d");
            (*charNo)++;
        }
        break;
    }
    case SDLK_e:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'e';
            printf("e");
            (*charNo)++;
        }
        break;
    }
    case SDLK_f:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'f';
            printf("f");
            (*charNo)++;
        }
        break;
    }
    case SDLK_g:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'g';
            printf("g");
            (*charNo)++;
        }
        break;
    }
    case SDLK_h:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'h';
            printf("h");
            (*charNo)++;
        }
        break;
    }
    case SDLK_i:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'i';
            printf("i");
            (*charNo)++;
        }
        break;
    }
    case SDLK_j:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'j';
            printf("j");
            (*charNo)++;
        }
        break;
    }
    case SDLK_k:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'k';
            printf("k");
            (*charNo)++;
        }
        break;
    }
    case SDLK_l:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'l';
            printf("l");
            (*charNo)++;
        }
        break;
    }
    case SDLK_m:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'm';
            printf("m");
            (*charNo)++;
        }
        break;
    }
    case SDLK_n:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'n';
            printf("n");
            (*charNo)++;
        }
        break;
    }
    case SDLK_o:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'o';
            printf("o");
            (*charNo)++;
        }
        break;
    }
    case SDLK_p:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'p';
            printf("p");
            (*charNo)++;
        }
        break;
    }
    case SDLK_q:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'q';
            printf("q");
            (*charNo)++;
        }
        break;
    }
    case SDLK_r:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'r';
            printf("r");
            (*charNo)++;
        }
        break;
    }
    case SDLK_s:{
        if ((*charNo)<5){
            guessWord[*charNo] = 's';
            printf("s");
            (*charNo)++;
        }
        break;
    }
    case SDLK_t:{
        if ((*charNo)<5){
            guessWord[*charNo] = 't';
            printf("t");
            (*charNo)++;
        }
        break;
    }
    case SDLK_u:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'u';
            printf("u");
            (*charNo)++;
        }
        break;
    }
    case SDLK_v:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'v';
            printf("v");
            (*charNo)++;
        }
        break;
    }
    case SDLK_w:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'w';
            printf("w");
            (*charNo)++;
        }
        break;
    }
    case SDLK_x:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'x';
            printf("x");
            (*charNo)++;
        }
        break;
    }
    case SDLK_y:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'y';
            printf("y");
            (*charNo)++;
        }
        break;
    }
    case SDLK_z:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'z';
            printf("z");
            (*charNo)++;
        }
        break;
    }
    case SDLK_RETURN:  //enter key
    {
        if ((*charNo)==5){
            printf("ENter");
            guessWord[5] = '\0';
            printf("\n%s", guessWord);
            switch(checkWord(charNo))
            {
                case CORRECT:   {
                    printf("CONGRATS YOU WON!");
                    gameRun = GAME_END_WIN;
                    break;
                }
                case WRONG:
                    break;
                case GAME_END_LOSE:
                    gameRun = GAME_END_LOSE;
                    break;
            }
            printf("guess no : %d", guessNo);
            for (i=0; i<5; i++){
                guessWord[i] = '\0';
            }

        }
        break;
    }
    case SDLK_BACKSPACE:{
        if ((*charNo)>0){
            (*charNo)--;
            guessWord[*charNo] = '\0';
        }
        break;
    }
    
    default:
        break;
    }
}
