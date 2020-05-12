#include "init.h"

void displayRules() {
	printf("\n\nAt each turn you have these options : spin the wheel and call a consonant. If your letter was in the puzzle you can then buy a vowel for $250, spin the wheel again or try to solve the puzzle. Each consonant is worth the money value of the field you hit. Contestants can continue spinning the wheel until they guess a wrong letter or hit Bankrupt / Lose a Turn. SAY LOWER AND UPPER IS SAME\n\n\n");
}

void displayGreetings() {
	printf("Hi guys welcome to the best game ever made by the greatest developers.");
}

char** getPuzzles() {
    char** sentences = NULL;

    if ((sentences = (char**)malloc(3 * sizeof(char*))) == NULL) {
        perror("Allocation of sentences failed");
        exit(1);
    }

    for (int i = 0; i < 3; i++){
        printf("Enter the sentence %d: ", i+1);
        sentences[i] = _strdup(my_gets(BUFFER_SIZE));
        sentences[i] = trimwhitespace(sentences[i]);
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
}

void freePuzzles(char** puzzles) {
    for (int i = 0; i < 3; i++) {
        free(puzzles[i]);
    }
    free(puzzles);
}