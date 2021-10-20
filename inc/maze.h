#ifndef MAZE_H
#define MAZE_H

/**
 * OS specific preprocessor directives for
 * SDL header inclusion
 */
#ifdef LINUX
#include <SDL2/SDL.h>
#elif defined(MAC)
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

/**
 * Other headers
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structures.h"
#include "macros.h"
#include "parser.h"
#include "player.h"

/**
 * SDL initialization prototypes
 */
void create_window(char *name, sdl_instance *sdl);
void safe_close_sdl(sdl_instance *sdl);
void create_renderer(sdl_instance *sdl);
void print_sdl_error();
/**
 * SDL events polling prototypes
 */
void game_event_loop(sdl_instance *sdl, map_t *map);
void poll_events(int *quit, SDL_Event *e, player *player, SDL_Point *mouse);

/**
 * SDL rendering prototypes
 */
void draw_2d_map(sdl_instance *sdl, map_t *map);
void send_frame(sdl_instance *sdl);
// map_t populate_map();

/**
 * RayCasting prototypes
 */
void raycast(sdl_instance *sdl, player *player,  map_t *map);
SDL_Point rotate_point(const SDL_Point *point, float cx, float cy, float deg, float ray_size);
SDL_Point check_ray_intersections(SDL_Point *center, double ray_rotation_angle, map_t map, double *ray_len);
void draw_3D_walls(sdl_instance *sdl, double ray_length, int index);
double remove_fish_eye_effect(player *player, double ray_length, double ray_view_angle);

void draw_untextured_ceiling(sdl_instance *sdl);
void draw_untextured_floor(sdl_instance *sdl);

#endif
