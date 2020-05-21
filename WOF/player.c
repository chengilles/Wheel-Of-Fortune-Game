#include "player.h"

int getPlayersNumber() {
	int numberOfPlayers;
	printf("\n");

	do {
		printf("How many players will be playing ? (2 or 3) ");
		scanf("%d", &numberOfPlayers);
		flushInput();
	} while (numberOfPlayers != 2 && numberOfPlayers != 3);

	printf("\n");
	return numberOfPlayers;
}

int chooseFirstPlayer(int playersNumber) {
	return rand() % (playersNumber);
}

Player* createPlayer(int index) {
	Player* p = NULL;

	if ((p = (Player*)malloc(sizeof(Player))) == NULL) {
		perror("Allocation of player failed");
		exit(1);
	}

	do {
		printf("Enter player %d's name: ", index + 1);
		if ((p->name = trimwhitespace(strdup(my_gets(BUFFER_SIZE)))) == NULL) {
			perror("Cannot copy the player name");
			exit(1);
		}
		if (strlen(p->name) < 3) {
			printf("The name should be at least 3 characters long\n");
		}
	} while (strlen(p->name) < 3);

	p->currentTurnMoney = 0;
	p->totalMoney = 0;
	p->canBuyVowel = false;

	return p;
}

Player** initPlayers(int playersNumber) {
	Player** players = NULL;

	if ((players = (Player**) realloc(players, playersNumber * sizeof(Player*))) == NULL) {
		perror("Allocation of players failed");
		exit(1);
	}

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