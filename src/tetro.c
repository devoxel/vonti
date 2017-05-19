#include "tetro.h"

Tetro* tetro_new_piece() {
	TetroType type = line;
	return tetro_init(type);
}

void create_points(TetroType type, Tetro* p) {
	for (int i = 0; i < TETRO_SIZE; i++) {
		p->points[i][0] = 1;
		p->points[i][1] = i;
	}
}

Tetro* tetro_init(TetroType type) {
	Tetro *p = malloc(sizeof(Tetro));
	p->x = 5;
	p->y = 0;
	p->type = type;
	create_points(type, p);
	return p;
}

void tetro_free(Tetro* p) {
	free(p);
	return;
}
