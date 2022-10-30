#ifndef __ANIMATED_TEXTURE_H__
#define __ANIMATED_TEXTURE_H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "Common.h"
#include "LTexture.h"

using std::vector;

class AnimatedTexture
{
public:
    int id;

    LTexture spriteTextureSheet;
    int currentClipIdx;
    int frameSpeed;
    int frameCount;
    int fHeight;
    int fWidth;

    vector<SDL_Rect> spriteClips;

    AnimatedTexture();

    void setValues(int fSpeed, int fC, int fH, int fW, int fStartX, int fStartY);

    bool loadFromFile(std::string path);

    void render(int posX, int posY);

    void free();
};

#endif