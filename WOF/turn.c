#include "turn.h"

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

int compare(const void* s1, const void* s2) {
    Player* p1 = *(Player**)s1;
    Player* p2 = *(Player**)s2;
    if (p1->totalMoney < p2->totalMoney)
        return 1;
    else if (p1->totalMoney > p2->totalMoney)
        return -1;
    else
        return 0;
}

void endGame(Player* players, int playersNumber) {
    qsort(players, playersNumber, sizeof(Player), compare);
    printf("\n---GAME STANDING---");
    for (int i = 0; i < playersNumber; i++) {
        printf("\n%d. %s [%d $]", i + 1, players[i].name, players[i].currentTurnMoney);
    }
    printf("\nThanks for playing !");
}

void addMoney(Player *ptr_player, int money){
    ptr_player->currentTurnMoney += money;
}

void nextPlayer(int currentPlayer){
    currentPlayer++;
}

void endRound(Player* players, int playersNumber, int currentRound){
    printf("\n---END OF ROUND %d---", currentRound);
    qsort(players,playersNumber, sizeof(Player), compare);
    for (int i = 0; i < playersNumber; i++) {
        printf("\n%d. %s [%d $]", i+1, players[i].name, players[i].currentTurnMoney);
    }
}