#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "turn.h"
#include "player.h"

void displayCurrentPlayer(Player* p) {
	printf("\n%s [%d $]", *(p->name), (p->currentTurnMoney));
}

void displayCurrentRound(int round) {
	printf("\nROUND %d", round);
}

void loadingBar() {
	system("color 2");
	char load[51] = "[------------------------------------------------]";
	for (int i = 1; i < 50; load[i++] = '|') {
		printf("\r%s", &load);
		Sleep(20);
	}
	system("color F");
}

void addMoney(Player *ptr_player, int money){
    ptr_player->currentTurnMoney += money;
}

void nextPlayer(int currentPlayer){
    currentPlayer++;
}

void endRound(Player players, int playersNumber, int currentRound){
    printf("\n---END OF ROUND %d---", currentRound);
    qsort(players,playersNumber, sizeof(Player), compare);
    for (int i = 0; i < playersNumber; i++) {
        printf("\n%d. %s [%d $]",i+1,players[i].name,players[i].currentTurnMoney);
    }
}