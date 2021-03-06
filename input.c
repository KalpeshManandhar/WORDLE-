#include "headers/input.h"
#include "headers/header.h"

int gameRun = 1;
char guessWord[6] = "";
char guesses[6][6] = {"", "", "", "", "", ""};

//  function for handling input from keyboard
void keyInput (SDL_Event* event, int *charNo){
    int i;
    switch (event->key.keysym.sym)
    {
    case SDLK_a:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'a';
            (*charNo)++;
        }
        break;
    }
    case SDLK_b:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'b';
            (*charNo)++;
        }
        break;
    }
    case SDLK_c:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'c';
            (*charNo)++;
        }
        break;
    }
    case SDLK_d:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'd';
            (*charNo)++;
        }
        break;
    }
    case SDLK_e:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'e';
            (*charNo)++;
        }
        break;
    }
    case SDLK_f:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'f';
            (*charNo)++;
        }
        break;
    }
    case SDLK_g:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'g';
            (*charNo)++;
        }
        break;
    }
    case SDLK_h:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'h';
            (*charNo)++;
        }
        break;
    }
    case SDLK_i:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'i';
            (*charNo)++;
        }
        break;
    }
    case SDLK_j:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'j';
            (*charNo)++;
        }
        break;
    }
    case SDLK_k:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'k';
            (*charNo)++;
        }
        break;
    }
    case SDLK_l:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'l';
            (*charNo)++;
        }
        break;
    }
    case SDLK_m:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'm';
            (*charNo)++;
        }
        break;
    }
    case SDLK_n:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'n';
            (*charNo)++;
        }
        break;
    }
    case SDLK_o:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'o';
            (*charNo)++;
        }
        break;
    }
    case SDLK_p:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'p';
            (*charNo)++;
        }
        break;
    }
    case SDLK_q:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'q';
            (*charNo)++;
        }
        break;
    }
    case SDLK_r:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'r';
            (*charNo)++;
        }
        break;
    }
    case SDLK_s:{
        if ((*charNo)<5){
            guessWord[*charNo] = 's';
            (*charNo)++;
        }
        break;
    }
    case SDLK_t:{
        if ((*charNo)<5){
            guessWord[*charNo] = 't';
            (*charNo)++;
        }
        break;
    }
    case SDLK_u:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'u';
            (*charNo)++;
        }
        break;
    }
    case SDLK_v:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'v';
            (*charNo)++;
        }
        break;
    }
    case SDLK_w:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'w';
            (*charNo)++;
        }
        break;
    }
    case SDLK_x:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'x';
            (*charNo)++;
        }
        break;
    }
    case SDLK_y:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'y';
            (*charNo)++;
        }
        break;
    }
    case SDLK_z:{
        if ((*charNo)<5){
            guessWord[*charNo] = 'z';
            (*charNo)++;
        }
        break;
    }
    case SDLK_RETURN:  //enter key
    {
        if ((*charNo)==5){
            guessWord[5] = '\0';
            switch(checkWord(charNo))
            {
                case CORRECT:   {
                    printf("CONGRATS YOU WON!");
                    gameRun = GAME_END_WIN;
                    break;
                }
                case WRONG:
                    break;
                case NOT_A_WORD:{
                    printf("\nNOT A WORD IN THE LIST\n");
                    break;
                }
                case GAME_END_LOSE:{
                    printf("YOU RAN OUT OF GUESSES :(\n THE WORD WAS: %s", chosenWord);
                    gameRun = GAME_END_LOSE;
                    break;
                }
            }
            // clears the guess 
            for (i=0; i<5; i++)
                guessWord[i] = '\0';
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
