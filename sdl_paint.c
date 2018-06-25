#include <stdio.h>
#include "paint.h"
#define NR_ROWS 14
#define NR_COLUMNS 36

#define TILE_WIDTH 35
#define TILE_HEIGHT 35
#define PLAYER 'p'
#define MONSTER 'm'
#define WALL 'w'
#define DOOR '#'
#define EMPTY_TILE '.'

int screen_x_location = 50;
int screen_y_location = 50;
SDL_Color color_wall = {119, 119, 119};
SDL_Color color_player = {0, 0, 255}; 
SDL_Color color_monster = {204, 0, 0}; 
SDL_Color color_space = {238, 238, 236}; 
void set_colors_for_squares(world* world_ptr);



int paint(world* world_ptr, SDL_Renderer *renderer, SDL_Texture *wall_texture,
	       	SDL_Texture *monster_texture, SDL_Texture *empty_tile_texture,
	       	SDL_Texture *player1_texture, SDL_Texture *door_texture, SDL_Texture *gameover_texture, int game_over, SDL_Texture *gamewin_texture, int game_win, SDL_Texture * start_texture, int start_prompt) {

       for(int Y=0; Y<NR_ROWS;Y++) {
		for(int X=0; X<NR_COLUMNS;X++) {
			if(Y == 0) {
				world_ptr->tile_types[Y][X].y = screen_y_location;
				if(X == 0) {
					world_ptr->tile_types[Y][X].x = screen_x_location;
				} else {
					world_ptr->tile_types[Y][X].x = world_ptr->tile_types[Y][X-1].x + TILE_WIDTH;
				}	
			} else {
				world_ptr->tile_types[Y][X].y = world_ptr->tile_types[Y-1][X].y + TILE_HEIGHT;
				if(X == 0) {
					world_ptr->tile_types[Y][X].x = screen_y_location;
				}else {
					world_ptr->tile_types[Y][X].x = world_ptr->tile_types[Y][X-1].x + TILE_WIDTH;
				}
			}

		}
	}


	SDL_SetRenderDrawColor(renderer,0,0,0,0);
	SDL_RenderClear(renderer);
	for(int Y = 0; Y<NR_ROWS;Y++) {
		for(int X = 0; X<NR_COLUMNS;X++) {
		
			if(world_ptr->tile_types[Y][X].type == WALL) {
				world_ptr->tile_types[Y][X].texture = wall_texture; 
				SDL_RenderCopy(renderer, world_ptr->tile_types[Y][X].texture, NULL, &(SDL_Rect) {
					       	world_ptr->tile_types[Y][X].x, world_ptr->tile_types[Y][X].y,
					       	TILE_WIDTH, TILE_HEIGHT});

			} else if (world_ptr->tile_types[Y][X].type == MONSTER) {
				world_ptr->tile_types[Y][X].texture = empty_tile_texture; 
				SDL_RenderCopy(renderer, world_ptr->tile_types[Y][X].texture, NULL, &(SDL_Rect) {
					       	world_ptr->tile_types[Y][X].x, world_ptr->tile_types[Y][X].y,
					       	TILE_WIDTH, TILE_HEIGHT});

				world_ptr->tile_types[Y][X].texture = monster_texture; 
				SDL_RenderCopy(renderer, world_ptr->tile_types[Y][X].texture, NULL, &(SDL_Rect) {
					       	world_ptr->tile_types[Y][X].x, world_ptr->tile_types[Y][X].y,
					       	TILE_WIDTH, TILE_HEIGHT});


			} else if (world_ptr->tile_types[Y][X].type == PLAYER) {

				world_ptr->tile_types[Y][X].texture = empty_tile_texture; 
				SDL_RenderCopy(renderer, world_ptr->tile_types[Y][X].texture, NULL, &(SDL_Rect) {
					       	world_ptr->tile_types[Y][X].x, world_ptr->tile_types[Y][X].y,
					       	TILE_WIDTH, TILE_HEIGHT});


				world_ptr->tile_types[Y][X].texture = player1_texture; 
				SDL_RenderCopy(renderer, world_ptr->tile_types[Y][X].texture, NULL, &(SDL_Rect) {
					       	world_ptr->tile_types[Y][X].x, world_ptr->tile_types[Y][X].y,
					       	TILE_WIDTH, TILE_HEIGHT});
			

			} else if (world_ptr->tile_types[Y][X].type == EMPTY_TILE) {

				world_ptr->tile_types[Y][X].texture = empty_tile_texture; 

				SDL_RenderCopy(renderer, world_ptr->tile_types[Y][X].texture, NULL, &(SDL_Rect) {
					       	world_ptr->tile_types[Y][X].x, world_ptr->tile_types[Y][X].y,
					       	TILE_WIDTH, TILE_HEIGHT});

			} else if (world_ptr->tile_types[Y][X].type == DOOR) { 

				world_ptr->tile_types[Y][X].texture = empty_tile_texture; 
				SDL_RenderCopy(renderer, world_ptr->tile_types[Y][X].texture, NULL, &(SDL_Rect) {
					       	world_ptr->tile_types[Y][X].x, world_ptr->tile_types[Y][X].y,
					       	TILE_WIDTH, TILE_HEIGHT});

				world_ptr->tile_types[Y][X].texture = door_texture; 
				SDL_RenderCopy(renderer, world_ptr->tile_types[Y][X].texture, NULL, &(SDL_Rect) {
					       	world_ptr->tile_types[Y][X].x, world_ptr->tile_types[Y][X].y,
					       	TILE_WIDTH, TILE_HEIGHT});
			}else {
				printf("error");
			}		
		}
	}
	SDL_Rect rect = {50, 525, 450, 150};
	if(game_over == 1) {
		SDL_RenderCopy(renderer, gameover_texture, NULL, &rect);	
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
		return 1;
	}
	if(game_win == 1) { 
		SDL_RenderCopy(renderer, gamewin_texture, NULL, &rect);	
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
		return 1;
	}
	if(start_prompt == 0) { 
		SDL_RenderCopy(renderer, start_texture, NULL, &rect);	
	}



	SDL_RenderPresent(renderer);

	return 0;
}



