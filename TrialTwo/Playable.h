#ifndef __PLAYABLE_H__
#define __PLAYABLE_H__

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cstdarg>
#include <vector>
#include <variant>
#include <map>

#include "common.h"
#include "Spiel.h"
#include "LTexture.h"
#include "CollidibleObject.h"

using std::vector;

class Playable : public CollidibleObject
{
public:
    static const int OBJ_VEL = 2;

    std::string currentEvent;

    std::map<std::string, std::variant<LTexture, AnimatedTexture>> textureMap;

    Playable();
    Playable(int x, int y);

    // Takes key presses and adjusts the dot's velocity
    void handleEvent(SDL_Event &e);

    // Moves the dot and checks collision
    void move(SDL_Rect &wall);
    void move(CollidibleObject &object);
    void move(int argc, ...);
    void move(vector<CollidibleObject> &objects);

    void bindTexture(LTexture &texture);
    void bindTexture(AnimatedTexture &texture);
    void bindTexture(std::string event, LTexture &texture);
    void bindTexture(std::string event, AnimatedTexture &texture);

    void render();

protected:
    // The velocity of the dot
    int mVelX, mVelY;
};

#endif