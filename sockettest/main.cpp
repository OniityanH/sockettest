#include "Feild.h"
#include <conio.h>
#include "stdio.h"
#include "snake.h"
#include <windows.h>
int main(void) {
	ini_snake();
	while (true) {
		system("cls");
		CreateField();
		GetMoveCMD();
		UpdateSnake();
	}
	return 0;
}
