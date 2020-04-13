#include "player.h"

int getPlayersNumber() {
	int numberOfPlayers;
	printf("How many players will be playing ? (2 or 3)\n");
	scanf_s("%d", &numberOfPlayers);
	return numberOfPlayers;
}

int chooseFirstPlayer() {
	srand(time(NULL));
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
	Player** arrayOfPlayer[3];
	Player* firstPlayer;
	Player* secondPlayer;
	Player* thirdPlayer;

	arrayOfPlayer[0] = firstPlayer;
	arrayOfPlayer[1] = firstPlayer;
	arrayOfPlayer[2] = firstPlayer;

	for (int i = 0; i < 2; i++){
		*(*arrayOfPlayer[i])->name = strdup(my_gets(BUFFER_SIZE));
		*(*arrayOfPlayer[i])->currentTurnMoney = 0;
		*(*arrayOfPlayer[i])->totalMoney = 0;
	}

	return arrayOfPlayer;
}





