#include <stdio.h>
#include <string.h>
#include <time.h>

char chosenWord[6], guessWord[6];
FILE * wordFile;
int guessNo = 0;

enum {
    GAME_END, WRONG, CORRECT, NOT_A_WORD, IS_A_WORD, CORRECT_PLACE, INCORRECT_PLACE, NOT_IN_WORD, DEF
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

void countLetters(char letter, int *countGuess, int *countChosen, int pos)
{
    int i; 
    (*countChosen) = 0;
    (*countGuess) = 0;
    for (i=0; i<5; i++){
        if (chosenWord[i] == letter)
            (*countChosen)++;
    }
    for (i=0; i<= pos; i++){
        if (guessWord[i] == letter)
            (*countGuess)++;
    }
}

void compare(conditions * guess)    {
    int i, j, countChosen = 0, countGuess = 0;
    for (i = 0; i< 5; i++)
    {
        countLetters(guessWord[i], &countGuess, &countChosen, i);
        (guess+i)->condition = DEF;
        for (j=0; j<5; j++)
        {
            if (guessWord[i] == chosenWord[j]){
                if (i == j)
                    (guess+i)->condition = CORRECT_PLACE;
                else
                    (guess+i)->condition = INCORRECT_PLACE;
            }
            if (countChosen < countGuess)
                (guess+i)->condition = NOT_IN_WORD;
        }
        if ((guess+i)->condition == DEF)
            (guess+i)->condition = NOT_IN_WORD;
    }
}

int checkWord()
{
    int i;
    if (strcmp(guessWord, chosenWord) == 0)
        return(CORRECT);
    else 
    {
        switch (isItAWord())
        {
        case IS_A_WORD:
        {   
            guessNo++;
            conditions guess[5];
            compare(&guess[0]);
            for (i=0; i<5; i++){
                switch (guess[i].condition)
                {
                case CORRECT_PLACE:
                    printf("%d - correct place\n", i);
                    break;
                case INCORRECT_PLACE:
                    printf("%d - incorrect place\n", i);
                    break;
                case NOT_IN_WORD:
                    printf("%d - not in word\n", i);
                    break;
                default:
                    break;
                }
            }

            break;
        }
        case NOT_A_WORD:
            printf("\nThat is not a word in the list\n");
        default:
            break;
        }
        if (guessNo == 5)
            return(GAME_END);
        return(WRONG);
    }
    
}

int main()
{
    int wordNo, flag = 1;
    wordNo = randomLineNumber();
    wordFile = fopen("data/words2.txt", "r");
    readChosenWord(wordNo);

    printf("Word is: %s\n", chosenWord);
    printf("Guess the word:\n");
    while(flag == 1)
    {
        scanf("%s", guessWord);
        guessWord[5]= '\0';
        switch (checkIfValid())
        {
        case VALID:
        {
            switch(checkWord())
            {
                case CORRECT:   {
                    printf("CONGRATS YOU WON!");
                    flag = GAME_END;
                    break;
                }
                case WRONG:
                    break;
                case GAME_END:
                    flag = GAME_END;
                    break;
            }
            break;
        }
        case NUM_INVALID:
        case LEN_INVALID:
            printf("invalid input");
        default:
            break;
        }

    }

    return(0);
}
