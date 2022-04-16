//
// Created by bossb on 16/04/2022.
//

#include "Actor.h"
#include "SpriteComponent.h"

void SpriteComponent::Draw(SDL_Renderer *renderer)
{
    if (mTexture)
    {
        SDL_Rect rect;
        rect.w = mTexWidth * mOwner->GetScale();
        rect.h = mTexHeight * mOwner->GetScale();
        Vector2 pos = mOwner->GetPosition();
        rect.x = pos.X - rect.w / 2;
        rect.y = pos.Y - rect.h / 2;
        SDL_RenderCopyEx(
                renderer,
                mTexture,
                nullptr,
                &rect,
                0.0,
                nullptr,
                SDL_FLIP_NONE
                );
    }
}

void SpriteComponent::SetTexture(SDL_Texture *texture)
{
    mTexture = texture;
    SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}
