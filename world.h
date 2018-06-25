#include "utility.h"
#include <SDL2/SDL.h>
#define NR_ROWS 14
#define NR_COLUMNS 37

#ifndef WORLD
#define WORLD




typedef struct{
	char type;
	SDL_Texture *texture;
	int x;
	int y;

}tile;



typedef struct{

	tile tile_types[NR_ROWS][NR_COLUMNS];
}world;



/* Returns an instance of world. */
world* create_world(void);

/* Loads the file into world, returns 1 on success and 0 on failure. */
int load_world(world *game, char* filename);

/* If player is in world, function returns the players coordinates or
 * otherwise returns NULL.*/
coord* get_player_coordinates(world *game);

/* If valid, function sets the players position and returns 1 or
 * otherwise returns 0.*/ 
int set_player_coordinates(world *game, int x, int y);

/* If valid, function moves the players position and returns 1 or
 * otherwise returns 0.*/ 
int move_player_coordinates( world *game, int x, int y);

/* If monster is in world, function returns players coordinates or
 * otherwise returns NULL.*/
coord* get_monster_coordinates(world *game);

/* If valid, function sets the monsters position and returns 1 or
 * otherwise returns 0.*/ 
int set_monster_coordinates(world *game, int x, int y);

/* If valid, function moves the players position and returns 1 or
 * otherwise returns 0.*/ 
int move_monster_coordinates( world *game, int x, int y);


#endif

