#include <stdio.h>
#include <string.h>
#include <time.h>

char chosenWord[6], guessWord[6];
FILE * wordFile;
int guessNo = 1;

enum {
    GAME_OVER, WRONG, CORRECT, NOT_A_WORD, IS_A_WORD, CORRECT_PLACE, INCORRECT_PLACE, NOT_IN_WORD, DEF
};

enum {
    VALID, NUM_INVALID, LEN_INVALID
};

typedef struct {
    int condition;
}conditions;

int randomLineNumber()
{
    int wordNo;
	srand(time(NULL));
	wordNo = rand()%12947;
	return(wordNo);
}

int checkIfValid()  {
    int i;
    for (i=0; i<5; i++)
    {
        if (guessWord[i] >= '0' && guessWord[i] <= '9')
            return(NUM_INVALID);
        if (guessWord[i] == '\0' || guessWord[i] == '\n' || guessWord[i] == '\t' || guessWord[i] == '\r')
            return(LEN_INVALID);
        if (guessWord[i] >= 'A' && guessWord[i] <= 'Z')
            guessWord[i] = guessWord[i] + ('a' - 'A');
    }
    return(VALID);
}


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

void readChosenWord (int wordNo) {
    fseek(wordFile, (long int) 7 * wordNo, SEEK_SET);
    fgets(chosenWord, 6, wordFile);
    chosenWord[5] = '\0';
}

int compare(conditions * guess)    {
    int i, j;
    for (i = 0; i< 5; i++)
    {
        for (j=0; j<5; j++)
        {
            if (guessWord[i] == chosenWord[j]){
                if (i == j)
                    guess->condition = CORRECT_PLACE;
                else
                    guess->condition = INCORRECT_PLACE;
            }else 
                guess->condition = NOT_IN_WORD;
        }
    }
}

int checkWord()
{
    char buffer[6];
    if (strcmp(guessWord, chosenWord) == 0)
        return(CORRECT);
    else 
    {
        switch (isItAWord())
        {
        case IS_A_WORD:
        {    
            conditions guess[5];
            compare(guess);
            break;
        }
        case NOT_A_WORD:
            printf("\nThat is not a word in the list");
        default:
            break;
        }
    }
    
}

int main()
{
    int wordNo, flag = 1;
    wordNo = randomLineNumber();
    wordFile = fopen("data/words2.txt", "r");
    readWord(wordNo);

    printf("Word is: %s\n", chosenWord);
    printf("Guess the word:\n");
    while(flag == 1)
    {
        scanf("%s", guessWord);
        guessWord[5]= '\0';
        switch (checkIfValid())
        {
        case VALID:
            /* code */
            break;
        case NUM_INVALID:
        case LEN_INVALID:
            printf("invalid input");
        default:
            break;
        }

    }

    return(0);
}