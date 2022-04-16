#pragma once

#include <vector>

class SDL_Window;
class SDL_Renderer;
class Actor;
class SpriteComponent;

class Game final
{
public:
    bool Initialize();
    void RunLoop();
    void ShutDown();

    void AddActor(Actor* actor);
    void RemoveActor(Actor* actor);

    void AddSprite(SpriteComponent* component);

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    SDL_Window *mWindow = nullptr;
    SDL_Renderer *mRenderer = nullptr;
    bool mIsRunning = true;
    bool mIsUpdate = false;
    uint32_t tickCount = 0;

    std::vector<Actor*> mActors{};
    std::vector<Actor*> mPendingAddActors{};

    std::vector<SpriteComponent*> mDrawOrders{};
};
