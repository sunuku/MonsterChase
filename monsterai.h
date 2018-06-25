#include "world.h"
#include "utility.h"

#ifndef MONSTERAI
#define MONSTERAI

/* If monster is in world,  function returns a position
 *  one space closer to the player or otherwise returns NULL.*/
coord* monster_chasing_algorithm(world* world);

#endif
