#include "turn.h"

void displayCurrentPlayer(Player* p) {
	printf("%s [%d $]\n", (p->name), (p->currentTurnMoney));
}

void displayCurrentRound(int round) {
	printf("\nROUND %d\n", round);
}

void red() {
    printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void reset() {
    printf("\033[0m");
}
    
void loadingBar() {
    int a = 24 + (rand() % 24);
    printf("%d\n\n\n", (a - 24));
	char load[26] = "[------------------------]";
	for (int i = 1; i < 26; load[i++] = '|') {
        if (load[i] == '|') {
            red();
        }
        else {
            yellow();
        }
		printf("%s\n", &load);
		Sleep(20);
        load[i] = '-';
	}
    reset();
}

int compare(const Player* s1, const Player* s2) {
    Player* p1 = *(Player**)s1;
    Player* p2 = *(Player**)s2;
    if (p1->totalMoney < p2->totalMoney)
        return 1;
    else if (p1->totalMoney > p2->totalMoney)
        return -1;
    else
        return 0;
}

void endRound(Player** players, int playersNumber) {
    qsort(players, playersNumber, sizeof(Player*), compare);
    for (int i = 0; i < playersNumber; i++) {
        printf("\n%d. %s [%d $]", i + 1, players[i]->name, players[i]->totalMoney);
    }
    printf("\n\n");
}

void addMoney(Player *ptr_player, int money){
    ptr_player->currentTurnMoney += money;
}