#pragma once
#include <stdio.h>
#include <string.h>

enum {
    GAME_END_WIN, WRONG, CORRECT, GAME_END_LOSE,   // check word
    NOT_A_WORD, IS_A_WORD,      // is it a word?
    CORRECT_PLACE, INCORRECT_PLACE, NOT_IN_WORD, DEF,       // position and condition 
    VALID, NUM_INVALID, LEN_INVALID                     // is it valid input?
};
// enum{
//     A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,ENTER,BACKSPACE
// };

typedef struct {
    int condition;
    
}conditions;

extern int guessNo;
extern int gameRun;
extern conditions previous[6][5];
extern char guesses[6][6];
extern char guessWord[6];


int isItAWord();
int checkWord(int *charNo);
void compare(conditions * guess);
int checkWord();