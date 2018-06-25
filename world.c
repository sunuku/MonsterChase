#include "world.h"
#include <stdio.h>
#include <stdlib.h>

#define NR_ROWS 14
#define NR_COLUMNS 37
#define PLAYER 'p'
#define MONSTER 'm'
#define WALL 'w'
#define EMPTY_TILE '.'

world* create_world(void) {
	world *world_ptr = (world *)malloc(sizeof(world));
	return world_ptr;
}

int load_world(world *world_ptr,  char* filename) {

	FILE* fp;
	char *str;
	str = filename;	
	if ((fp = fopen(str ,"r")) == NULL) {
		return 0;
	} else {

		for(int Y=0;Y<NR_ROWS;Y++) {
			for(int X=0;X<NR_COLUMNS;X++)
				fscanf(fp,"%c",&world_ptr->tile_types[Y][X].type);
		}

		fclose(fp);
		return 1;
	}
	

}

int set_player_coordinates(world* world_ptr, int x, int y) { 
	
	coord* playloc = get_player_coordinates(world_ptr);
	
	world_ptr->tile_types[playloc->y][playloc->x].type = EMPTY_TILE; 

	int result = 0;
	for(int Y = 0; Y<NR_ROWS; Y++) {
		for(int X = 0;X<NR_COLUMNS;X++) {
			if ( X == x && Y == y) {
				world_ptr->tile_types[y][x].type = PLAYER;
				result = 1;       
			}
		}
	}
	return result;

}


coord* get_player_coordinates(world* world_ptr) {

	coord *playercoord = (coord*)malloc(sizeof(coord));
	if( world_ptr == NULL) {
		return NULL;
	}

	int n = 0;
	for(int Y = 0;Y<NR_ROWS;Y++) {
		for(int X = 0; X<NR_COLUMNS;X++) {
			if(world_ptr->tile_types[Y][X].type == PLAYER) {
				playercoord->x = X;
				playercoord->y = Y;
				n = 1;
				break;
			}
		}
	}
	if( n==0) {
		return NULL;
	}
	return playercoord;

}

int move_player_coordinates(world* world_ptr, int x, int y) {
	coord *playloc = get_player_coordinates(world_ptr);

	if (world_ptr->tile_types[playloc->y + y][playloc->x + x].type != WALL && world_ptr->tile_types[playloc->y + y][playloc->x + x].type != MONSTER) {
		set_player_coordinates(world_ptr, playloc->x + x, playloc->y +y);
		return 1;
	}
	if (world_ptr->tile_types[playloc->y + y][playloc->x + x].type != EMPTY_TILE) {
		return 0;

	}
}

int set_monster_coordinates(world* world_ptr, int x, int y) { 
        coord* monloc = get_monster_coordinates(world_ptr);
 
        world_ptr->tile_types[monloc->y][monloc->x].type = EMPTY_TILE;

         int result = 0;
         for(int Y = 0; Y<NR_ROWS; Y++) {
                 for(int X = 0;X<NR_COLUMNS;X++) {
                         if ( X == x && Y == y) {
                                 world_ptr->tile_types[y][x].type = MONSTER;
                                 result = 1;
                         }
                 }
         }
         return result;
 
}



coord* get_monster_coordinates(world* world_ptr) {

	coord *monstercoord = (coord*)malloc(sizeof(coord));
	if( world_ptr == NULL) {
		return NULL;
	}

	int n = 0;
	for(int Y = 0;Y<NR_ROWS;Y++) {
		for(int X = 0; X<NR_COLUMNS;X++) {
			if(world_ptr->tile_types[Y][X].type == MONSTER) {
				monstercoord->x = X;
				monstercoord->y = Y;
				n = 1;
				break;
			}
		}
	}
	if( n==0) {
		return NULL;
	}
	return monstercoord;

}

int move_monster_coordinates(world* world_ptr, int x, int y) {



        coord *monloc = get_monster_coordinates(world_ptr);

        if (world_ptr->tile_types[monloc->y + y][monloc->x + x].type != WALL) {
                set_monster_coordinates(world_ptr, monloc->x + x, monloc->y +y);
                return 1;
        }
        if (world_ptr->tile_types[monloc->y + y][monloc->x + x].type == WALL) {
                return 0;

        }

}


