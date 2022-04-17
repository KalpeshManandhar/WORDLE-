enum {
    GAME_END, WRONG, CORRECT,   // check word
    NOT_A_WORD, IS_A_WORD,      // is it a word?
    CORRECT_PLACE, INCORRECT_PLACE, NOT_IN_WORD, DEF,       // position and condition 
    VALID, NUM_INVALID, LEN_INVALID                     // is it valid input?
};

typedef struct {
    int condition;
    
}conditions;