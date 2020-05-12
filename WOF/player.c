#include "player.h"

int getPlayersNumber() {
	int numberOfPlayers;

	do {
		printf("\nHow many players will be playing ? (2 or 3) ");
		scanf_s("%d", &numberOfPlayers);
		while (getchar() != '\n');
	} while (numberOfPlayers != 2 && numberOfPlayers != 3);

	printf("\n");
	flushInput();

	return numberOfPlayers;
}

int chooseFirstPlayer(int playersNumber) {
	return rand() % (playersNumber);
}


Player* createPlayer(int index) {
	Player* p = NULL;
	p = malloc(sizeof(Player));

	printf("Enter player %d's name: ", index+1);
	p->name = trimwhitespace(_strdup(my_gets(BUFFER_SIZE)));
	p->currentTurnMoney = 0;
	p->totalMoney = 0;
	p->canBuyVowel = false;

	return p;
}

Player** initPlayers(int playersNumber) {
	Player** players = NULL;
	players = realloc(players, playersNumber * sizeof(Player*));

	for (int i = 0; i < playersNumber; i++) {
		Player* p = createPlayer(i);
		players[i] = p;
	}

	return players;
}

void freePlayers(Player** players, int playersNumber) {
	for (int i = 0; i < playersNumber; i++) {
		free(players[i]->name);
		free(players[i]);
	}
	free(players);
}