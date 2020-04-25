#include "player.h"

int getPlayersNumber() {
	int numberOfPlayers;
	do {
		printf("How many players will be playing ? (2 or 3) ");
		scanf_s("%d", &numberOfPlayers);
	} while (numberOfPlayers != 2 && numberOfPlayers != 3);
	return numberOfPlayers;
}

int chooseFirstPlayer() {
	return rand() % (getPlayersNumber());
}

char* getPlayerNames(int playersNumber) {
	flushInput();
	char** playerNames = NULL;
	playerNames = realloc(playerNames, playersNumber * sizeof(char*));

	for (int i = 0; i < playersNumber; i++){
		printf("Enter player %d's name: ", i + 1);
		playerNames[i] = _strdup(my_gets(BUFFER_SIZE));
	}

	return playerNames;
}

Player** initPlayers() {
	int numberPlayer = getPlayersNumber();
	Player** arrayOfPlayer = NULL;
	arrayOfPlayer = malloc(arrayOfPlayer, numberPlayer * sizeof(Player*));

	for (int i = 0; i < numberPlayer; i++) {
		arrayOfPlayer[i]->name = _strdup(my_gets(BUFFER_SIZE));
		arrayOfPlayer[i]->currentTurnMoney = 0;
		arrayOfPlayer[i]->totalMoney = 0;
	}

	return arrayOfPlayer;
}





