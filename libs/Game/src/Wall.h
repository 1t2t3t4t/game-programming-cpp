#pragma once

#include <Game/GameObject.h>
#include <Math/Rect.h>

class Wall : public GameObject
{
public:
    Wall(Rect rect) : mRect(rect) {}

    virtual void Update() override;
    virtual void Draw() override;

private:
    Rect mRect;
};