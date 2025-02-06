#pragma once

class GameObject
{
public:
    virtual ~GameObject();

    virtual void Update() = 0;
    virtual void Draw() = 0;
};