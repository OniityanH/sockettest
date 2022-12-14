#include <stdio.h>
#include "Feild.h"
#include "snake.h"

int i;
int j;

void GameOver() {
	printf("GAME OVER");
}

bool IsConner(int i, int j) {
	if (i == 0 && j == 0) {
		return true;
	}
	else if (i == 0 && j == MapLength - 1) {
		return true;
	}
	else if (i == MapLength - 1 && j == 0) {
		return true;
	}
	else if (i == MapLength - 1 && j == MapLength - 1) {
		return true;
	}
	else {
		return false;
	}
	return false;
}

bool IsWallZ(int i, int j) {
	if (IsConner(i, j) == false) {
		if (j == 0 || j == MapLength - 1) {
			return true;
		}
	}
	return false;
}

bool IsWallH(int i, int j) {
	if (IsConner(i, j) == false) {
		if (i == 0 || i == MapLength - 1) {
			return true;
		}
	}
	return false;
}

bool isEndLine(int i) {
	if (i == MapLength - 1) {
		return true;
	}
	return false;
}

bool DrawSnake(Snake* tempsnake, int i, int j) {
	if (i == tempsnake->SnakeHeadi) {
		if (j == tempsnake->SnakeHeadj) {
			return 1;
		}
	}
	return 0;
};

bool DrawGoal(Goal* tempgoal, int i, int j) {
	if (i == tempgoal->positioni) {
		if (j == tempgoal->positionj) {
			return 1;
		}
	}
	return 0;
}

void CreateField(void) {
	Snake* tempsnake = getSnake();
	Goal* tempgoal = getGoal();
	int isSnakeDrew = 0;
	int isGoalDrew = 0;
	for (j = 0; j < MapLength; j++) {
		for (i = 0; i < MapLength; i++) {
			isSnakeDrew = DrawSnake(tempsnake, i, j);
			isGoalDrew = DrawGoal(tempgoal, i, j);
			if (IsConner(i, j) == true) {
				printf("%c", CONNER);
			}
			else if (IsWallH(i, j) == true) {
				printf("%c", WALLH);
			}
			else if (IsWallZ(i, j) == true) {
				printf("%c", WALLZ);
			}
			else {
				if (isSnakeDrew == 1) {
					printf("*");
				}
				else if (isGoalDrew == 1) {
					printf("@");
				}
				else {
					printf(" ");
				}
			}
			if (isEndLine(i) == true) {
				printf("\n");
			}
		}
		i = 0;
	}
	printf("Score: %d", getScore());
}