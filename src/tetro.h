#ifndef TETRO_H
#define TETRO_H
#include <stdio.h>
#include <stdlib.h>

#define TETRO_SIZE 4
#define POINT_SIZE 2
#define POINT_Y 1
#define POINT_X 2

typedef enum {
	line
} TetroType;

typedef struct {
	TetroType type;
	int x;
	int y;
	int points[TETRO_SIZE][POINT_SIZE];
} Tetro;

Tetro* tetro_init(TetroType type);
Tetro* tetro_new_piece();
void tetro_free(Tetro* p);

#endif // END TETRO_H
