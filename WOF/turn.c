#include "turn.h"

void displayCurrentPlayer(Player* p) {
	printf("%s [%d $]\n", (p->name), (p->currentTurnMoney));
}

void displayCurrentRound(int round) {
	printf("\nROUND %d\n", round);
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

int compareEndGame(const Player* s1, const Player* s2) {
    Player* p1 = *(Player**)s1;
    Player* p2 = *(Player**)s2;
    if (p1->totalMoney < p2->totalMoney)
        return 1;
    else if (p1->totalMoney > p2->totalMoney)
        return -1;
    else
        return 0;
}

int compareEndRound(const Player* s1, const Player* s2) {
    Player* p1 = *(Player**)s1;
    Player* p2 = *(Player**)s2;
    if (p1->currentTurnMoney < p2->currentTurnMoney)
        return 1;
    else if (p1->currentTurnMoney > p2->currentTurnMoney)
        return -1;
    else
        return 0;
}

void endGame(Player** players, int playersNumber) {
    qsort(players, playersNumber, sizeof(Player*), compareEndGame);
    printf("\n---GAME STANDING---");
    for (int i = 0; i < playersNumber; i++) {
        printf("\n%d. %s [%d $]", i + 1, players[i]->name, players[i]->totalMoney);
    }
    printf("\n\nThanks for playing !\n\n\n");
}

void addMoney(Player *ptr_player, int money){
    ptr_player->currentTurnMoney += money;
}

void endRound(Player** players, int playersNumber, int currentRound){
    qsort(players, playersNumber, sizeof(Player*), compareEndRound);
    printf("\n---END OF ROUND %d---", currentRound);
    for (int i = 0; i < playersNumber; i++) {
        printf("\n%d. %s [%d $]", i + 1, players[i]->name, players[i]->totalMoney);
    }
    printf("\n\n");
}