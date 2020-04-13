#include "wheel.h"
#include <string.h>

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}

int getOccurrence(char *puzzle,char *currentPuzzle, int c){
    int occurrence = 0;
    for(int i = 0; i < strlen(puzzle); i++){
        if(c == puzzle[i]){
            occurrence++;
            currentPuzzle[i] = c;
        }
    }
    return occurrence;
}

    
   
    
    