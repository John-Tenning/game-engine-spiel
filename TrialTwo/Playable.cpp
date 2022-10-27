#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cstdarg>

#include "common.h"
#include "Basics.h"
#include "LTexture.h"
#include "CollidibleObject.h"
#include "Playable.h"

Playable::Playable() : CollidibleObject()
{
    // Initialize the velocity
    mVelX = 0;
    mVelY = 0;
};

Playable::Playable(int x, int y) : CollidibleObject(x, y)
{
    // Initialize the velocity
    mVelX = 0;
    mVelY = 0;
};

void Playable::handleEvent(SDL_Event &e)
{
    // If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            mVelY -= OBJ_VEL;
            break;
        case SDLK_DOWN:
            mVelY += OBJ_VEL;
            break;
        case SDLK_LEFT:
            mVelX -= OBJ_VEL;
            break;
        case SDLK_RIGHT:
            mVelX += OBJ_VEL;
            break;
        }
    }
    // If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            mVelY += OBJ_VEL;
            break;
        case SDLK_DOWN:
            mVelY -= OBJ_VEL;
            break;
        case SDLK_LEFT:
            mVelX += OBJ_VEL;
            break;
        case SDLK_RIGHT:
            mVelX -= OBJ_VEL;
            break;
        }
    }
}

void Playable::move(SDL_Rect &wall)
{
    // Move the dot left or right
    mPosX += mVelX;
    mCollider.x = mPosX;

    // If the dot collided or went too far to the left or right
    if ((mPosX < 0) || (mPosX + OBJ_WIDTH > SCREEN_WIDTH) || checkCollision(mCollider, wall))
    {
        // Move back
        mPosX -= mVelX;
        mCollider.x = mPosX;
    }

    // Move the dot up or down
    mPosY += mVelY;
    mCollider.y = mPosY;

    // If the dot collided or went too far up or down
    if ((mPosY < 0) || (mPosY + OBJ_HEIGHT > SCREEN_HEIGHT) || checkCollision(mCollider, wall))
    {
        // Move back
        mPosY -= mVelY;
        mCollider.y = mPosY;
    }
}

void Playable::move(CollidibleObject &object)
{
    // Move the dot left or right
    mPosX += mVelX;
    mCollider.x = mPosX;

    // If the dot collided or went too far to the left or right
    if ((mPosX < 0) || (mPosX + OBJ_WIDTH > SCREEN_WIDTH) || checkCollision(mCollider, object.getColliderRect()))
    {
        // Move back
        mPosX -= mVelX;
        mCollider.x = mPosX;
    }

    // Move the dot up or down
    mPosY += mVelY;
    mCollider.y = mPosY;

    // If the dot collided or went too far up or down
    if ((mPosY < 0) || (mPosY + OBJ_HEIGHT > SCREEN_HEIGHT) || checkCollision(mCollider, object.getColliderRect()))
    {
        // Move back
        mPosY -= mVelY;
        mCollider.y = mPosY;
    }
}

void Playable::move(int argc, ...)
{
    // Move the dot left or right
    mPosX += mVelX;
    mCollider.x = mPosX;
    bool isXCollided = (mPosX < 0) || (mPosX + OBJ_WIDTH > SCREEN_WIDTH);

    mPosY += mVelY;
    mCollider.y = mPosY;
    bool isYCollided = (mPosY < 0) || (mPosY + OBJ_HEIGHT > SCREEN_HEIGHT);

    va_list args;
    va_start(args, argc);

    for (int i = 0; i < argc; i++)
    {
        CollidibleObject obj = va_arg(args, CollidibleObject);
        isXCollided = isXCollided || checkCollision(mCollider, obj.getColliderRect());
        isYCollided = isYCollided || checkCollision(mCollider, obj.getColliderRect());
    }
    va_end(args);
    // If the dot collided or went too far to the left or right
    if (isXCollided)
    {
        // Move back
        mPosX -= mVelX;
        mCollider.x = mPosX;
    }
    // If the dot collided or went too far to the left or right
    if (isYCollided)
    {
        // Move back
        mPosY -= mVelY;
        mCollider.y = mPosY;
    }
}
