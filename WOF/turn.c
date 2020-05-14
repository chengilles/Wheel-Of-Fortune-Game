#include "turn.h"

void displayCurrentPlayer(Player* p) {
	printf("%s [%d $]\t\t", (p->name), (p->currentTurnMoney));
}

void displayCurrentRound(int round) {
    printf("\033[1;31m\n################ ROUND %d ################\033[0m\n", round);
}
   
void loadingBar(int random) {
    printf("\n");
    random += 25;
    char load[27] = "[------------------------]";

    for (int i = 1; i < (random + 2); i++) {
        load[i % 25] = '|';

        printf("\r");
        for (int j = 0; j < 26; j++) {
            if (j == (i % 25))
                printf("\033[0m");
            else
                printf("\033[1;31m");
            printf("%c", load[j]);
        }
        Sleep(80);
        load[i % 25] = '-';
        if (i == 24) i++;
    }
    printf("\033[0m");
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
        printf("\n %d. %s [%d $]", i + 1, players[i]->name, players[i]->totalMoney);
    }
    printf("\n\n");
}

void addMoney(Player *ptr_player, int money){
    ptr_player->currentTurnMoney += money;
}