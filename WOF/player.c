#include "player.h"

int getPlayersNumber() {
	int numberOfPlayers;
	do {
		printf("\nHow many players will be playing ? (2 or 3) ");
		scanf_s("%d", &numberOfPlayers);
	} while (numberOfPlayers != 2 && numberOfPlayers != 3);
	printf("\n");
	return numberOfPlayers;
}

int chooseFirstPlayer() {
	return rand() % (getPlayersNumber());
}


Player* createPlayer(int index) {
	Player* p = NULL;
	p = malloc(sizeof(Player));

	printf("Enter player %d's name: ", index+1);
	p->name = _strdup(my_gets(BUFFER_SIZE));
	p->currentTurnMoney = 0;
	p->totalMoney = 0;

	return p;
}

Player** initPlayers() {
	int playersNumber = getPlayersNumber();
	flushInput();

	Player** players = NULL;
	players = realloc(players, playersNumber * sizeof(Player*));

	for (int i = 0; i < playersNumber; i++) {
		Player* p = createPlayer(i);
		players[i] = p;
	}

	return players;
}





