#ifndef __COLLIDIBLE_OBJECT_H__
#define __COLLIDIBLE_OBJECT_H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "LTexture.h"

class CollidibleObject
{
public:
    static const int OBJ_WIDTH = 32;
    static const int OBJ_HEIGHT = 32;

    CollidibleObject();
    CollidibleObject(int x, int y);

    void setColliderCoords(int x, int y);
    void render(LTexture &texture);
    SDL_Rect getColliderRect();

private:
    int mPosX, mPosY;
    SDL_Rect mCollider;
};

#endif