#include "player.h"

int getPlayersNumber() {
	int numberOfPlayers;
	printf("How many players will be playing ? (2 or 3)\n");
	scanf_s("%d", &numberOfPlayers);
	return numberOfPlayers;
}

int chooseFirstPlayer() {
	// Should be called in the main : srandTime(NULL)
	return rand() % (getPlayersNumber());
}

char* getPlayerNames() {
	Player** arrayOfPlayer[3] = initPlayers();
	char* playerNames[3];

	char* firstPlayerName = *(*arrayOfPlayer[0])->name;
	char* secondPlayerName = *(*arrayOfPlayer[1])->name;
	char* thirdPlayerName = *(*arrayOfPlayer[2])->name;

	playerNames[0] = firstPlayerName;
	playerNames[1] = firstPlayerName;
	playerNames[2] = firstPlayerName;

	return playerNames;
	
}

Player** initPlayers() {
	int numberOfPlayers = malloc(sizeof(int) * getPlayersNumber());
	Player** arrayOfPlayer = numberOfPlayers;

	for (int i = 0; i < numberOfPlayers; i++) {
		arrayOfPlayer[i]->name = strdup(my_gets(BUFFER_SIZE));
		arrayOfPlayer[i]->currentTurnMoney = 0;
		arrayOfPlayer[i]->totalMoney = 0;
	}

	return arrayOfPlayer;
}





