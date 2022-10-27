#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "common.h"
#include "Basics.h"
#include "CollidibleObject.h"

CollidibleObject::CollidibleObject()
{
    // Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    // Set collision box dimension
    mCollider.w = OBJ_WIDTH;
    mCollider.h = OBJ_HEIGHT;
}

void CollidibleObject::render()
{
    // Show the dot
    gDotTexture.render(mPosX, mPosY);
}