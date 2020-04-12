#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "turn.h"
#include "player.h"

void displayCurrentPlayer(Player* p) {
	printf("\n%s [%d $]", *(p->name), (p->currentTurnMoney));
}