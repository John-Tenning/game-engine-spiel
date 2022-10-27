#ifndef __COLLIDIBLE_OBJECT_H__
#define __COLLIDIBLE_OBJECT_H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

class CollidibleObject
{
public:
    static const int OBJ_WIDTH;
    static const int OBJ_HEIGHT;
    CollidibleObject();

    ~CollidibleObject();

    void render();

private:
    int mPosX, mPosY;
    SDL_Rect mCollider;
}

#endif