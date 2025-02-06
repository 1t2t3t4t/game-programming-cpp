#pragma once

#include <Math/Vec2.h>

struct Rect
{
    Rect(Vec2 center, Vec2 extend) : mCenter(center), mExtend(extend) {}

private:
    Vec2 mCenter;
    Vec2 mExtend;
};