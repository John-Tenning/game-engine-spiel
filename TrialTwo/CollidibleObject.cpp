#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "common.h"
#include "Spiel.h"
#include "LTexture.h"
#include "CollidibleObject.h"
#include "AnimatedTexture.h"

CollidibleObject::CollidibleObject()
{
    // Initialize the offsets
    mPosX = 0;
    mPosY = 0;
    mCollider.x = mPosX;
    mCollider.y = mPosY;

    // Set collision box dimension
    mCollider.w = OBJ_WIDTH;
    mCollider.h = OBJ_HEIGHT;
}

CollidibleObject::CollidibleObject(int x, int y)
{
    // Initialize the offsets
    mPosX = x;
    mPosY = y;
    mCollider.x = mPosX;
    mCollider.y = mPosY;

    // Set collision box dimension
    mCollider.w = OBJ_WIDTH;
    mCollider.h = OBJ_HEIGHT;
}

void CollidibleObject::render()
{
    // Show the dot
    currentTexture->render(mPosX, mPosY);
}

void CollidibleObject::render(AnimatedTexture &texture)
{
    texture.render(mPosX, mPosY);
}

void CollidibleObject::setColliderCoords(int x, int y)
{
    // OBJ_WIDTH = x;
    // OBJ_HEIGHT = y;
    mCollider.w = x;
    mCollider.y = y;
}

SDL_Rect CollidibleObject::getColliderRect()
{
    return mCollider;
}

void CollidibleObject::bind(LTexture &texture){
    currentTexture = &texture;
}