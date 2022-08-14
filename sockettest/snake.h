#pragma once

#define INIBODYLENGTH 0
#define BYTE_8	unsigned char

struct Snake {
	BYTE_8 SnakeHeadi;
	BYTE_8 SnakeHeadj;
	int	SnakeLength;
	int SnakeLengthi[MapLength * MapLength];
	int SnakeLengthj[MapLength * MapLength];
};

struct Goal {
	BYTE_8 positioni;
	BYTE_8 positionj;
	BYTE_8 score;
};

extern Snake* getSnake(void);

int getScore();

extern void UpdateSnake();

extern void ini_snake(void);

void UpdateScore();

void UPdateNewGoal();

extern void ini_goal();

extern void GetMoveCMD();

extern Goal* getGoal();