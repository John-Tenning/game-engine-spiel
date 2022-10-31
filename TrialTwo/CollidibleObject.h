#ifndef __COLLIDIBLE_OBJECT_H__
#define __COLLIDIBLE_OBJECT_H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "LTexture.h"
#include "AnimatedTexture.h"

class CollidibleObject
{
public:
    static const int OBJ_WIDTH = 32;
    static const int OBJ_HEIGHT = 32;

    LTexture *currentTexture;

    CollidibleObject();
    CollidibleObject(int x, int y);

    void setColliderCoords(int x, int y);
    void render();
    void bind(LTexture &texture);
    void render(AnimatedTexture &texture);
    SDL_Rect getColliderRect();

protected:
    SDL_Rect mCollider;
    int mPosX, mPosY;
};

#endif