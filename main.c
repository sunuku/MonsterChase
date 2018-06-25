#include "monsterai.h"
#include "world.h"
#include "utility.h"
#include "paint.h"
#include <SDL2/SDL_ttf.h>








SDL_Renderer * renderer;
SDL_Window * window;
int setup(void);
int eventloop(world *world_ptr);
int main(void) { 
	setup(); 
	world *world_ptr = create_world();
       	load_world(world_ptr, "lvl1");
	int level = 1;
       	int done = 0;
	TTF_Font *font = TTF_OpenFont("OpenSans-Light.ttf", 500);
	SDL_Color red = {255,0,0};
	SDL_Color green = {0,255,0};
	SDL_Color white = {255,255,255};
       	SDL_Surface *wall_surface = SDL_LoadBMP("wall1.bmp");
       	SDL_Surface *door_surface = SDL_LoadBMP("door.bmp");
       	SDL_Surface *monster_surface = SDL_LoadBMP("skelly1.bmp");
	SDL_Surface *empty_tile_surface = SDL_LoadBMP("empty_tile.bmp");
	SDL_Surface *player1_surface = SDL_LoadBMP("player1.bmp");
	SDL_Surface *gameover_surface = TTF_RenderText_Solid(font, "GAME OVER", red);
	SDL_Surface *gamewin_surface = TTF_RenderText_Solid(font, "YOU WIN", green);
	SDL_Surface *start_surface = TTF_RenderText_Solid(font, "Press spacebar to begin", white);


	SDL_Texture *start_texture = SDL_CreateTextureFromSurface(renderer, start_surface);
	SDL_Texture *gameover_texture = SDL_CreateTextureFromSurface(renderer, gameover_surface);
	SDL_Texture *gamewin_texture = SDL_CreateTextureFromSurface(renderer, gamewin_surface);
	SDL_Texture *door_texture = SDL_CreateTextureFromSurface(renderer, door_surface);
	SDL_Texture *wall_texture = SDL_CreateTextureFromSurface(renderer, wall_surface);
	SDL_Texture *monster_texture = SDL_CreateTextureFromSurface(renderer, monster_surface);
	SDL_Texture *empty_tile_texture = SDL_CreateTextureFromSurface(renderer, empty_tile_surface);
	SDL_Texture *player1_texture = SDL_CreateTextureFromSurface(renderer, player1_surface);

	SDL_FreeSurface(start_surface);
	SDL_FreeSurface(gameover_surface);
	SDL_FreeSurface(gamewin_surface);
	SDL_FreeSurface(empty_tile_surface);
	SDL_FreeSurface(player1_surface);
	SDL_FreeSurface(monster_surface);
	SDL_FreeSurface(wall_surface);
	
	int start_prompt = 0;
	int game_over = 0;
	int game_win = 0;

	while(!done) {
		
		if (start_prompt == 0) {
			SDL_Event event;
			while(SDL_PollEvent(&event)){
				if(event.type = SDL_KEYDOWN) 
					if(event.key.keysym.sym == SDLK_ESCAPE) {
						return 1;
					}
					if(event.key.keysym.sym == SDLK_SPACE) {
						start_prompt = 1;
						break;
					}
			}
		}

		else if (start_prompt != 0) {
			
			

			
			coord *playloc = get_player_coordinates(world_ptr);
			if(level ==1 && playloc->x == 30 && playloc->y == 0) {
				load_world(world_ptr, "lvl2");
				level = 2;

			} else if(level == 2 && playloc->x == 4 && playloc->y == 0) {
				load_world(world_ptr, "lvl3");
				level = 3;

			} else if(level == 3 && playloc->x == 1 && playloc->y == 0) {
				game_win = 1;
			}

				
			done = eventloop(world_ptr);

			coord *playloc1 = get_player_coordinates(world_ptr);
			if(playloc1 == NULL) {
				game_over = 1;
			}
		}
				
		int done1 = paint(world_ptr, renderer, wall_texture, monster_texture, empty_tile_texture, player1_texture,
			       	door_texture, gameover_texture, game_over, gamewin_texture, game_win, start_texture, start_prompt);
		if(done1 == 1) {
			return 1;
		}

		

	}

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

}
int setup() {
	TTF_Init();
        SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow( "An SDL2 window", SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED, 1680, 900, 0 );
        if (window == NULL) {
                printf("Could not create window: %s\n", SDL_GetError());
                return 1;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);


}


int eventloop(world *world_ptr) {
	int done = 0;
	SDL_Event event;
        while(SDL_PollEvent(&event)){
		coord *monloc = get_monster_coordinates(world_ptr);
		if(event.key.repeat == 0) {
			switch(event.type){
				case SDL_WINDOWEVENT_CLOSE:
					if(window){
						SDL_DestroyWindow(window);
						window = NULL;
						done = 1;
						break;
					}
				

				case SDL_KEYDOWN: 
					switch(event.key.keysym.sym) {

						case SDLK_ESCAPE:
							done = 1;
							return 1;	
						
						 case SDLK_w:	
							move_player_coordinates(world_ptr, 0, -1);	
							if(monloc == NULL) {
								break;
							}
							coord *v1 = monster_chasing_algorithm(world_ptr);
							move_monster_coordinates(world_ptr, v1->x, v1->y);
							break;

						 case SDLK_a:
							move_player_coordinates(world_ptr, -1, 0);	
							if(monloc == NULL) {
								break;
							}
							coord *v2 = monster_chasing_algorithm(world_ptr);
							move_monster_coordinates(world_ptr, v2->x, v2->y);
							break;

						 case SDLK_s:
							move_player_coordinates(world_ptr, 0, 1);	
							if(monloc == NULL) {
								break;
							}
							coord *v3 = monster_chasing_algorithm(world_ptr);
							move_monster_coordinates(world_ptr, v3->x, v3->y);
							break;
							
						 case SDLK_d: 
							move_player_coordinates(world_ptr, 1, 0);	
							if(monloc == NULL) {
								break;
							}
							coord *v4 = monster_chasing_algorithm(world_ptr);
							move_monster_coordinates(world_ptr, v4->x, v4->y);
							break;
						
						default: 
							break;

							 
					}
			}
		}
	}
}
	

