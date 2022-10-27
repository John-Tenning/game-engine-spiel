#ifndef __PLAYABLE_H__
#define __PLAYABLE_H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cstdarg>

#include "common.h"
#include "Basics.h"
#include "LTexture.h"
#include "CollidibleObject.h"

class Playable : public CollidibleObject
{
    public:
    static const int OBJ_VEL = 2;

    Playable();
    Playable(int x, int y);

    // Takes key presses and adjusts the dot's velocity
    void handleEvent(SDL_Event &e);

    // Moves the dot and checks collision
    void move(SDL_Rect &wall);
    void move(CollidibleObject &object);
    void move(int argc, ...);

protected:
    // The velocity of the dot
    int mVelX, mVelY;
};

#endif