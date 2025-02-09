#pragma once

#include "SDL3/SDL_render.h"

class GameObject
{
public:
    virtual ~GameObject();

    virtual void Update() = 0;
    virtual void Draw(SDL_Renderer *renderer) = 0;
};
