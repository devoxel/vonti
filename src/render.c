#include "render.h"

static SDL_Texture* TetroTex = NULL;

void destroy_textures() {
	SDL_DestroyTexture(TetroTex);
	return;
}

static int create_textures(SDL_Renderer* screen) {
	puts("creating tetro texture");
	SDL_Surface* tetrosurf = SDL_LoadBMP("tetro.bmp");
	if (tetrosurf == NULL) {
		puts("Failure loading surface");
		return -1;
	}
	TetroTex = SDL_CreateTextureFromSurface(screen, tetrosurf);
	SDL_FreeSurface(tetrosurf);
	if (TetroTex == NULL) {
		puts("Failure loading texture");
		return -1;
	}
	return 0;
}

void render(SDL_Window* window, SDL_Renderer* screen, Tetro* current_piece, int** board) {
	if (TetroTex == NULL) {
		create_textures(screen);
	}
	int width;
	int height;

	SDL_GetWindowSize(window, &width, &height);
	render_grid(screen, width, height);
	render_board(screen, board, width, height);
	render_piece(screen, current_piece, width, height);

	return;
}

void render_piece(SDL_Renderer* screen, Tetro* p, int width, int height) {
	for(int i = 0; i < TETRO_SIZE; i++) {
		render_tetro_piece(
			screen,
			p->points[i][0] + p->x,
			p->points[i][1] + p->y,
			width,
			height
		);
	}
	return;
}

void render_board(SDL_Renderer* screen, int** board, int width, int height) {
	for(int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			if (board[i][j] != 0) {
				render_tetro_piece(screen, i, j, width, height);
			}
		}
	}
}

void render_grid(SDL_Renderer* screen, int width, int height) {

	// base color: 002b36
	SDL_SetRenderDrawColor(screen, 0x00, 0x2E, 0x36, 255);
	SDL_RenderClear(screen);
	// line color: eee8d5
	SDL_SetRenderDrawColor(screen, 0xEE, 0xE8, 0xD5, 255);
	for (int y = 0; y < height; y += height/22) {
		SDL_RenderDrawLine(screen, 0, y, width, y);
	}
	for (int x = 0; x < width; x += width/10) {
		SDL_RenderDrawLine(screen, x, 0, x, height);
	}
	return;
}

void render_tetro_piece(SDL_Renderer* screen, int x, int y, int width, int height) {
	SDL_Rect r;
	r.x = x * (width/10) + 1;
	r.y = y * (height/22) + 1;
	r.w = (width/10) - 1;
	r.h = (height/22) - 1;

	// red: dc322f
	SDL_SetRenderDrawColor(screen, 0xDC, 0x32, 0x2F, 255);
	SDL_RenderCopy(screen, TetroTex, NULL, &r);
	return;
}
