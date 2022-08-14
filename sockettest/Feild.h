#pragma once

#define MapLength 20
#define CONNER 0x2b
#define WALLH 0x7c
#define WALLZ 0x2d
#define SPACE 0x20
#define ENDLINE 0x0d

bool IsConner(int i, int j);

bool IsWallZ(int i, int j);

bool IsWallH(int i, int j);

bool isEndLine(int i);

void CreateField(void);
