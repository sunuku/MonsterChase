#include "world.h"

#ifndef PAINT
#define PAINT

/* Prints world to screen.*/
int paint(world* screen, SDL_Renderer* renderer, SDL_Texture *wall_texture,
	       	SDL_Texture *monster_texture, SDL_Texture *empty_tile_texture,
	       	SDL_Texture *player1_texture, SDL_Texture *door_texture, SDL_Texture *gameover_texture, int game_over, SDL_Texture *gamewin_texture, int game_win, SDL_Texture *start_texture, int start_prompt);
#endif
