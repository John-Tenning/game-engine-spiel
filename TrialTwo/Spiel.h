#ifndef __SPIEL_H__
#define __SPIEL_H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Spiel.h"

// Starts up SDL and creates window
bool SPIEL_init();

// Frees media and shuts down SDL
void SPIEL_close();

// Box collision detector
bool SPIEL_checkCollision(SDL_Rect a, SDL_Rect b);

void SPIEL_clearScreen();

#endif