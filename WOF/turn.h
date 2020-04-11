#ifndef TURN_H
#define TURN_H

// Selects a new puzzle, set money to 0, print winner.
void endRound();

// Increments the initPlayer var.
int nextPlayer();

// Displays current player name + his money.
void displayCurrentPlayer();

// Displays current round.
void displayCurrentRound();

// Adds money to player.
void addMoney(Player*, int money);

// Displays the loading bar.
void loadingBar();

// Displays the winner and the final standing.
void endGame();

#endif /* TURN_H */