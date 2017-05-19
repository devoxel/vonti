#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tetro.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 22

int** init_board();
void destroy_board(int** board);
void board_add(int** board, Tetro* p);
bool tetro_gravity(int** board, Tetro* p);

#endif // END RENDER_H
