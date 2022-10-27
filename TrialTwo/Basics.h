#ifndef __BASICS_H__
#define __BASICS_H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Basics.h"

// Starts up SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// Box collision detector
bool checkCollision(SDL_Rect a, SDL_Rect b);

#endif