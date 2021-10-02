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
#include "structures.h"
#include <stdio.h>

/**
 * SDL initialization prototypes
 */
int create_window(char *name, sdl_globals *sdl_g);
void safe_close_sdl(sdl_globals *sdl_g);

/**
 * SDL events polling prototypes
 */
void loop_and_poll(sdl_globals *sdl_g);
void poll_events(int *quit, SDL_Event *e);

#endif