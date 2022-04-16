//
// Created by bossb on 16/04/2022.
//

#pragma once

#include <SDL_render.h>
#include "Component.h"

class SpriteComponent : public Component
{
public:
    explicit SpriteComponent(Actor *owner, int drawOrder = 100) : Component(owner), mDrawOrder(drawOrder)
    {};

    virtual void Draw(SDL_Renderer* renderer);
    virtual void SetTexture(SDL_Texture* texture);

    int GetDrawOrder() const { return mDrawOrder; }
    int GetTexHeight() const { return mTexHeight; }
    int GetTexWidth() const { return mTexWidth; }

protected:

    // Texture to draw
    SDL_Texture* mTexture{};

    // Draw order used for painter's algorithm
    int mDrawOrder;

    // Width/height of texture
    int mTexWidth{};
    int mTexHeight{};
};
