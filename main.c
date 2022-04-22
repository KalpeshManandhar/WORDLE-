#include <time.h>
#include "headers/graphics.h"
#include "headers/header.h"

FILE * wordFile;
conditions guess[5];
char chosenWord[6];

int guessNo = 0;

int randomLineNumber(){     // random number generate for random word selection
    int wordNo;
	srand(time(NULL));
	wordNo = rand()%12947;
	return(wordNo);
}


// kinda obsolete at this point as only letter inputs are taken 
// was used to make the basic structure before adding graphics
/*int checkIfValid()  {      
    int i;
    for (i=0; i<5; i++)
    {
        if (guessWord[i] >= '0' && guessWord[i] <= '9')
            return(NUM_INVALID);
        if (guessWord[i] == '\0' || guessWord[i] == ' ' || guessWord[i] == '\n' || guessWord[i] == '\t' || guessWord[i] == '\r')
            return(LEN_INVALID);
        if (guessWord[i] >= 'A' && guessWord[i] <= 'Z')
            guessWord[i] = guessWord[i] + ('a' - 'A');
    }
    return(VALID);
}*/


// checks if the word is listed as a valid word in the word file
int isItAWord() {       
    char buffer[6];
    fseek(wordFile, 0, SEEK_SET);
    while(!feof(wordFile))
    {
        fgets(buffer, 6, wordFile);
        buffer[5] = '\0';
        if  (strcmp(buffer, guessWord) == 0)
            return(IS_A_WORD);
    }
    return(NOT_A_WORD);
}


// reads word from file
void readChosenWord (int wordNo) {
    fseek(wordFile, (long int) 7 * wordNo, SEEK_SET);
    fgets(chosenWord, 6, wordFile);
    chosenWord[5] = '\0';
}

// counts number of instances of an alphabet in the guessword upto a specific position
// and total number of instances of the alphabet in the chosen word
void countLetters(char letter, int *countGuess, int *countChosen, int pos, int *countGuessAfter)
{
    int i; 
    (*countChosen) = 0;
    (*countGuess) = 0;
    (*countGuessAfter) = 0;
    for (i=0; i<5; i++){
        if (chosenWord[i] == letter)
            (*countChosen)++;
    }
    for (i=0; i<= pos; i++){
        if (guessWord[i] == letter)
            (*countGuess)++;
    }
    for (i=pos; i<5; i++){
        if (guessWord[i] == letter)
            (*countGuessAfter)++;
    }
}

// compares the guess to the chosen word and sets the position of alphabets as CORRECT or INCORRECT
void compare(conditions * guess)    {
    int i, j, countChosen = 0, countGuess = 0, countGuessAfter = 0;
    int repeat = 0;
    char repeatCheck = '\0';
    for (i = 0; i< 5; i++)
    {
        countLetters(guessWord[i], &countGuess, &countChosen, i, &countGuessAfter);
        (guess+i)->condition = DEF;
        for (j=0; j<5; j++)
        {
            if (guessWord[i] == chosenWord[j]){
                if (i == j)
                    (guess+i)->condition = CORRECT_PLACE;
                else{
                    if ((guess+i)->condition != CORRECT_PLACE)
                        (guess+i)->condition = INCORRECT_PLACE;
                }
            }
            // if (repeat > countChosen && guessWord[i] == repeatCheck &&(guess+i)->condition != CORRECT_PLACE)
            // {
            //     (guess+i)->condition = NOT_IN_WORD;
            // }
            // else{
            //     if ((guess+i)->condition != CORRECT_PLACE)
            //             (guess+i)->condition = INCORRECT_PLACE;
            // }



            if ((guessWord[i] == repeatCheck))
            {
                if (repeat >= countChosen)
                    (guess+i)->condition = NOT_IN_WORD;
            }
            // if (countChosen < countGuess && (guess+i)->condition != CORRECT_PLACE)
            //     (guess+i)->condition = NOT_IN_WORD;
            if (countGuessAfter > countChosen){    
                if ((guess+i)->condition != CORRECT_PLACE){
                    (guess+i)->condition = NOT_IN_WORD;
                }
                else{
                    repeat++;
                    repeatCheck = guessWord[i];
                    break;
                }
            }
            // else if (countGuessAfter == countChosen)
            // {
            //     if ((guess+i)->condition == CORRECT_PLACE){
            //         repeat++;
            //         repeatCheck = guessWord[i];
            //     }
            //     else{
            //         (guess+i)->condition = INCORRECT_PLACE;
            //     }
            // }
        }
        if ((guess+i)->condition == DEF)
            (guess+i)->condition = NOT_IN_WORD;
    }
}


int checkWord(int *charNo)
{
    int i;
    if (strcmp(guessWord, chosenWord) == 0)
    {
        for (i=0; i<5; i++){
            guesses[guessNo][i] = guessWord[i]; 
            previous[guessNo][i].condition = CORRECT_PLACE;
        }
        guessNo++;
        return(CORRECT);
    }
    else {
        switch (isItAWord()){
        case IS_A_WORD:
        {   
            (*charNo)=0;
            compare(&guess[0]);
            for (i=0; i<5; i++)
            {
                guesses[guessNo][i] = guessWord[i]; 
                previous[guessNo][i].condition = guess[i].condition;
            }
            guessNo++;
            break;
        }
        case NOT_A_WORD:{
            (*charNo)=0;
            return(NOT_A_WORD);
        }
        default:
            break;
        }
        if (guessNo == 6)
            return(GAME_END_LOSE);
        return(WRONG);
    }
}

int main(int argc, char **argv)
{
    int wordNo;
    wordNo = randomLineNumber();
    wordFile = fopen("data/words.txt", "r");

    // reads random word from file
    readChosenWord(wordNo);

    printf("Word is: %s\n", chosenWord);

    // main game loop
    gameLoop(argc, argv);
    return(0);
}
