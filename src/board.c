#include "board.h"

int** init_board() {
	// XXX: Should be able to simplify this with C99 syntax
	int** x;
	x = malloc(BOARD_HEIGHT * sizeof(int*));
	if (x == NULL) {
		return NULL;
	}
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		x[i] = calloc(BOARD_WIDTH, sizeof(int));
		if (x[i] == NULL) {
			destroy_board(x);
			return NULL;
		}
	}
	return x;
}

void destroy_board(int** board) {
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		free(board[i]);
	}
	free(board);
	return;
}

void board_add(int** board, Tetro* p) {
	for (int i = 0; i < TETRO_SIZE; i++) {
		puts("added piece to board");
		int ix = p->points[i][0];
		int iy = p->points[i][1];
		board[p->y+iy][p->y+ix] = 1;
	}
}

bool tetro_gravity(int** board, Tetro* p) {
	int nexty = p->y + 1;

	for (int i = 0; i < TETRO_SIZE; i++) {
		int ix = p->points[i][0];
		int iy = p->points[i][1];
		if (nexty+iy > (BOARD_HEIGHT-1)) {
			return true;
		}
		if (board[nexty+iy][p->x+ix] != 0) {
			return true;
		}
	}

	p->y = p->y + 1;
	return false;
}
