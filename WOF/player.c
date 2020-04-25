#include "player.h"

int getPlayersNumber() {
	int numberOfPlayers;
	printf("How many players will be playing ? (2 or 3)\n");
	scanf_s("%d", &numberOfPlayers);
	return numberOfPlayers;
}

int chooseFirstPlayer() {
	return rand() % (getPlayersNumber());
}

char* getPlayerNames() {
	int numberPlayer = getPlayersNumber();
	char* playerNames = NULL;
	playerNames = malloc(playerNames, numberPlayer * sizeof(char*));

	for (int i = 0; i < numberPlayer; i++){
		playerNames[i] = my_gets(playerNames[i])->name;
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





