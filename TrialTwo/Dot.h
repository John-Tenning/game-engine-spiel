#ifndef __DOT_H__
#define __DOT_H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "LTexture.h"
#include "CollidibleObject.h"

// The dot that will move around on the screen
class Dot
{
public:
    // The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;

    // Maximum axis velocity of the dot
    static const int DOT_VEL = 2;

    // Initializes the variables
    Dot();

    // Takes key presses and adjusts the dot's velocity
    void handleEvent(SDL_Event &e);

    // Moves the dot and checks collision
    void move(SDL_Rect &wall);
    void move(CollidibleObject &object);
    void move(int argc, ...);

    // Shows the dot on the screen
    void render(LTexture &texture);

private:
    // The X and Y offsets of the dot
    int mPosX, mPosY;

    // The velocity of the dot
    int mVelX, mVelY;

    // Dot's collision box
    SDL_Rect mCollider;
};

#endif