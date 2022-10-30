
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Common.h"
#include "LTexture.h"
#include "AnimatedTexture.h"

AnimatedTexture::AnimatedTexture()
{
    frameSpeed = 0;
    frameCount = 0;
    fHeight = 0;
    fWidth = 0;
    currentClipIdx = 0;
}

void AnimatedTexture::setValues(int fSpeed, int fC, int fW, int fH, int fStartX, int fStartY)
{
    frameSpeed = fSpeed;
    frameCount = fC;
    fHeight = fH;
    fWidth = fW;
    currentClipIdx = 0;

    for (int i = 0; i < frameCount; i++)
    {
        SDL_Rect tempRect;
        tempRect.x = fStartX + (i * fWidth);
        tempRect.y = fStartY;
        tempRect.w = fWidth;
        tempRect.h = fHeight;
        spriteClips.push_back(tempRect);
    }
}

bool AnimatedTexture::loadFromFile(std::string path)
{
    return spriteTextureSheet.loadFromFile(path);
}

void AnimatedTexture::render(int posX, int posY)
{
    int relIdx = (timeFrame) % (frameCount * frameSpeed);
    int clipIdx = relIdx / frameSpeed;
    currentClipIdx = clipIdx;
    spriteTextureSheet.render(posX, posY, &spriteClips[currentClipIdx]);
}

void AnimatedTexture::free()
{
    spriteTextureSheet.free();
}