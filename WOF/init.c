#include "init.h"

void displayRules() {
	printf("\n\nAt each turn you have these options : spin the wheel and call a consonant. If your letter was in the puzzle you can then buy a vowel for $250, spin the wheel again or try to solve the puzzle. Each consonant is worth the money value of the field you hit. Contestants can continue spinning the wheel until they guess a wrong letter or hit Bankrupt / Lose a Turn.\n\n");
}

void displayGreetings() {
	printf("Hi guys welcome to the best game ever made by the greatest developers.");
}

char** getPuzzles() {
    char** sentences = NULL;

    sentences = malloc(3 * sizeof(char*));

    for (int i = 0; i < 3; i++){
        printf("Enter the sentence %d: ", i+1);
        sentences[i] = _strdup(my_gets(BUFFER_SIZE));
    }

    return sentences;
}

void displayLogo() {
    FILE* myFile = NULL;
    myFile = fopen("./ressources/wofLogzo.txt", "r");
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