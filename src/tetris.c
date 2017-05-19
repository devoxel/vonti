#include "tetris.h"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	SDL_Window *window;
	window = SDL_CreateWindow(
		"vonti",                           // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		300,                               // width, in pixels
		660,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);
	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}


	SDL_Renderer *screen;
	screen =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	int** board;
	board = init_board();
	printf("%p\n", (void*)board);
	unsigned int FPS = 120;
	int GRAVITY_UPDATE_TIMER = 30;
	int gravity_timer = 0;
	Tetro* current_piece = NULL;

	while (1) {
		unsigned int ctick = SDL_GetTicks();

		if (current_piece == NULL) {
			current_piece = tetro_new_piece();
		}

		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_Log("Program quit after %i ticks", e.quit.timestamp);
				goto cleanup;
			}
		}

		render(window, screen, current_piece, board);
		SDL_RenderPresent(screen);

		gravity_timer += 1;
		if (gravity_timer >= GRAVITY_UPDATE_TIMER) {
			gravity_timer = 0;
			bool collided = tetro_gravity(board, current_piece);
			if (collided) {
				puts("Adding collision");
				board_add(board, current_piece);
				// check for score finish and modify board
				current_piece = NULL;
			}
		}

		if ((1000/FPS) > SDL_GetTicks() - ctick) {
			SDL_Delay(1000 / (FPS - (SDL_GetTicks()-ctick)));
		}
	}

	cleanup:
		tetro_free(current_piece);
		destroy_board(board);
		destroy_textures();
		SDL_DestroyRenderer(screen);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
}
