#include "io.h"

#ifndef INIT_H
#define INIT_H

//Displays the rules of the WOF game.
void displayRules();

//Takes 3 sentences input from the User/Host to use in the WOF game.
char** getPuzzles();

//Displays Greetings at the start of the WOF game.
void displayGreetings();

//Displays the logo of the WOF game
void displayLogo();

//Trim the spaces at the begining and the end of a string
char* trimwhitespace(char* str);

//Free the 3 puzzles
void freePuzzles(char** puzzles);

#endif /* INIT_H */
