//
// Created by bossb on 16/04/2022.
//
#pragma once

#include <vector>
#include "Vector2.h"

class Game;

enum class State
{
    Active,
    Paused,
    Dead
};

class Actor
{
public:
    explicit Actor(Game* game) : mGame(game), mState(State::Active)
    {}

    virtual ~Actor() = default;

    // Update function called from Game (not overridable)
    void Update(float deltaTime);

    // Updates all the components attached to the actor (not overridable)
    void UpdateComponents(float deltaTime);

    // Any actor-specific update code (overridable)
    virtual void UpdateActor(float deltaTime)
    {};

    void AddComponent(class Component* component);
    void RemoveComponent(class Component* component);

    State GetState() const;

    float GetScale() const { return mScale; }
    float GetRotation() const { return mRotation; }
    Vector2 GetPosition() const { return mPosition; }

protected:
    // Actor's state
    State mState;

    // Transform
    Vector2 mPosition{};
    float mScale{};
    float mRotation{};

    // Components held by this actor
    std::vector<class Component*> mComponents{};

private:
    Game* mGame;
};

