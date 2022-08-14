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

int MoveUpdated = 0;
unsigned char MoveDirection = 0;

Snake g_Snake;

Snake* getSnake() {
	return &g_Snake;
}

int getMoveUpdated() {
	return MoveUpdated;
}


void ini_snake() {
	int i = 0;
	int j = 0;
	Snake* gSnake = getSnake();
	while(true){
		if (i >= 2 && i <= MapLength - 2) {
			break;
		}
		else {
			srand(time(NULL));
			i = rand() % MapLength;
		}
	}
	while(true){
		if (j >= 2 && j <= MapLength - 2) {
			break;
		}
		else {
			srand(time(NULL));
			j = rand() % MapLength;
		}
	}
	gSnake->SnakeHeadi = i;
	gSnake->SnakeHeadj = j;
	gSnake->SnakeLength = 0;
}


void GetMoveCMD() {
	MoveDirection = _getch();
	MoveUpdated = 1;
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