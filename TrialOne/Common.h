#ifndef __COMMON_H__
#define __COMMON_H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "LTexture.h"

extern SDL_Renderer *gRenderer;
extern SDL_Window *gWindow;
extern LTexture gDotTexture;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

#endif