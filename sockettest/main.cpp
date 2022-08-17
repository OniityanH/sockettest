#include "Feild.h"
#include <conio.h>
#include "stdio.h"
#include "snake.h"
#include <windows.h>
#include <time.h>
int main(void) {
	ini_snake();
	srand(time(NULL));
	ini_goal();
	while (true) {
		system("cls");
		CreateField();
		GetMoveCMD();
		UpdateSnake();
		UpdateScore();
		if (IsSnakeDead() == 1) {
			GameOver();
			break;
		}
		UPdateNewGoal();
	}
	return 0;
}