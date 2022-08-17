#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Feild.h"
#include "snake.h"
#include <time.h>

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define w 0x77
#define s 0x73
#define a 0x61
#define d 0x64
#define GOAL_SCORE 10;

int MoveUpdated = 0;
int Score = 0;
unsigned char MoveDirection = 0;
Goal gGoal;
Snake g_Snake;
bool ReNewGoal;

bool HitWall() {
	if (getSnake()->SnakeHeadi == 0 || getSnake()->SnakeHeadi == MapLength - 1) {
		return 1;
	}
	if (getSnake()->SnakeHeadj == 0 || getSnake()->SnakeHeadj == MapLength - 1) {
		return 1;
	}
}

bool IsSnakeDead() {
	if (HitWall() == true) {
		return 1;
	}
/*if (HitSelf() == true) {
		return 1;
	}
*/
	return 0;
}

int getScore() {
	return Score;
}
Snake* getSnake() {
	return &g_Snake;
}

int getMoveUpdated() {
	return MoveUpdated;
}
void UPdateNewGoal() {
	int i, j;
	if (ReNewGoal == 1) {
		srand(time(NULL) + rand());
		i = rand() % MapLength;
		gGoal.positioni = i;

		srand(time(NULL) + rand() * 2);
		j = rand() % MapLength;
		gGoal.positioni = j;
	}
}

void UpdateScore() {
	Snake* lSnake = getSnake();
	Goal* lgoal = getGoal();
	ReNewGoal = 0;
	if (lSnake->SnakeHeadi == lgoal->positioni && lSnake->SnakeHeadj == lgoal->positionj) {
		Score += lgoal->score;
		ReNewGoal = 1;
	}
}

void ini_snake() {
	int i = 0;
	int j = 0;
	Snake* gSnake = getSnake();
	srand(time(NULL));
	while (true) {
		if (i >= 2 && i <= MapLength - 2) {
			break;
		}
		else {
			srand(time(NULL) + rand());
			i = rand() % MapLength;
		}
	}
	srand(time(NULL));
	while (true) {
		if (j >= 2 && j <= MapLength - 2) {
			break;
		}
		else {
			srand(time(NULL) + rand() * 4);
			j = rand() % MapLength;
		}
	}
	gSnake->SnakeHeadi = i;
	gSnake->SnakeHeadj = j;
	gSnake->SnakeLength = 0;
}

void ini_goal() {
	int i = 0;
	int j = 0;
	while (true) {
		if (i >= 2 && i <= MapLength - 2) {
			break;
		}
		else {
			srand(time(NULL) + rand() * 2);
			i = rand() % MapLength;
		}
	}
	while (true) {
		if (j >= 2 && j <= MapLength - 2) {
			break;
		}
		else {
			srand(time(NULL) + rand() * 3);
			j = rand() % MapLength;
		}
	}
	gGoal.positioni = i;
	gGoal.positionj = j;
	gGoal.score = GOAL_SCORE;
}

void GetMoveCMD() {
	MoveDirection = _getch();
	MoveUpdated = 1;
}

Goal* getGoal() {
	return &gGoal;
}

int movingDirection(Snake* tempsnake) {
	if (MoveDirection == w) {
		return UP;
	}
	else if (MoveDirection == s) {
		return DOWN;
	}
	else if (MoveDirection == a) {
		return RIGHT;
	}
	else if (MoveDirection == d) {
		return LEFT;
	}
	else {
		;
	}
	return 0;
}

void moveForward(Snake* tempsnake) {
	if (movingDirection(tempsnake) == LEFT) {
		tempsnake->SnakeHeadi += 1;
	}
	else if (movingDirection(tempsnake) == RIGHT) {
		tempsnake->SnakeHeadi -= 1;
	}
	else if (movingDirection(tempsnake) == UP) {
		tempsnake->SnakeHeadj -= 1;
	}
	else if (movingDirection(tempsnake) == DOWN) {
		tempsnake->SnakeHeadj += 1;
	}
}

void UpdateSnake() {
	Snake* tempsnake = getSnake();
	moveForward(tempsnake);
}