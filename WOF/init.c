#include "init.h"

void displayRules() {
	printf("\n\nIf you would like to know how the game works in detail, please consider the Readme\nYou can not buy or enter a vowel on your first turn in a Round.\nIf you land on a wedge containing money value, a correct guess of a letter will grant you the Occurrence \nof that Letter in the Puzzle * The Money value you landed on. You can only guess the Puzzle if you are asked to do so.\nYou don't have to guess the \"whitespaces\" in between Words in the Puzzle.\n\n\n");
}

void displayGreetings() {
	printf("Welcome to Wheel of Fortune.");
}

char** getPuzzles() {
    char** sentences = NULL;

    if ((sentences = (char**)malloc(3 * sizeof(char*))) == NULL) {
        perror("Allocation of puzzle failed");
        exit(1);
    }

    for (int i = 0; i < 3; i++){
        printf("Enter the sentence %d: ", i+1);
        if ((sentences[i] = trimwhitespace(strdup(my_gets(BUFFER_SIZE)))) == NULL) {
            perror("Cannot copy the puzzle");
            exit(1);
        }
    }

    return sentences;
}

char* trimwhitespace(char* str) {
    char* end;

    while (isspace((unsigned char)*str)) str++;
    if (*str == 0)
        return str;

    end = str + strlen(str) - 1;
    while (end > str&& isspace((unsigned char)*end)) end--;
    end[1] = '\0';

    return str;
}

void displayLogo() {
    printf("\033[0;32m");
    FILE* myFile = NULL;
    myFile = fopen("./ressources/wofLogo.txt", "r");
    if (myFile != NULL) {
        char charReaded = fgetc(myFile);
        while (charReaded != EOF) {
            printf("%c", charReaded);
            charReaded = fgetc(myFile);
        }
        fclose(myFile);
    } else {
        printf("--------------WOF--------------\n");
        printf("------loading_file_error-------\n");
        printf("--Please contact the support---\n\n");
    }
    printf("\033[0m");
}

void freePuzzles(char** puzzles) {
    for (int i = 0; i < 3; i++) {
        free(puzzles[i]);
    }
    free(puzzles);
}