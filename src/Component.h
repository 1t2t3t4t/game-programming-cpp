//
// Created by bossb on 16/04/2022.
//

#pragma once

class Actor;

class Component
{
public:
    explicit Component(Actor* owner, int updateOrder = 100) : mOwner(owner), mUpdateOrder(updateOrder)
    {}
    virtual ~Component() = default;

    virtual void Update(float deltaTime) = 0;

    int GetUpdateOrder() const
    {
        return mUpdateOrder;
    }

protected:
    Actor* mOwner;
    int mUpdateOrder;
};
