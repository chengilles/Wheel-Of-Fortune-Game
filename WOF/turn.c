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