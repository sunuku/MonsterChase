#include "monsterai.h"
#define WALL 'w'



coord* monster_chasing_algorithm(world* world_ptr) {
	
	coord *original_monloc = get_monster_coordinates(world_ptr);
	coord *playloc = get_player_coordinates(world_ptr);
	coord *new_monloc = (coord*)malloc( sizeof(coord));	
	new_monloc->x = 0;
	new_monloc->y = 0;



	if(playloc->y > original_monloc->y && world_ptr->tile_types[original_monloc->y+1][original_monloc->x].type != WALL) {
		new_monloc->y = 1;

	} else if(playloc->y < original_monloc->y && world_ptr->tile_types[original_monloc->y-1][original_monloc->x].type != WALL) {
		new_monloc->y = -1;

	}
	
       	if(playloc->x > original_monloc->x && world_ptr->tile_types[original_monloc->y][original_monloc->x+1].type != WALL) {
		new_monloc->x = 1;

	} else if(playloc->x < original_monloc->x && world_ptr->tile_types[original_monloc->y][original_monloc->x-1].type != WALL) {
		new_monloc->x = -1;

	}


	return new_monloc;
}
		
