#pragma once

#define INIBODYLENGTH 0

struct Snake {
	int SnakeHeadi;
	int SnakeHeadj;
	int SnakeLength;
};

extern Snake* getSnake(void);

void UpdateSnake();

void ini_snake(void);

void GetMoveCMD();
