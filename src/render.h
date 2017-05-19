#ifndef RENDER_H
#define RENDER_H
#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "tetro.h"
#include "board.h"

void render(
	SDL_Window* window,
	SDL_Renderer* screen,
	Tetro* current_piece,
	int** board
);
void destroy_textures();

void render_piece(SDL_Renderer* screen, Tetro* current_piece, int width, int height);
void render_board(SDL_Renderer* screen, int** board, int width, int height);
void render_grid(SDL_Renderer* screen, int width, int height);
void render_tetro_piece(SDL_Renderer* screen, int x, int y, int width, int height);

#endif // END RENDER_H
