#pragma once

#include <memory>
#include <vector>

class SDL_Window;
class SDL_Renderer;

class GameObject;

class Game
{
public:
    Game() = default;
    ~Game();

    bool Init();
    void RunLoop();

private:
    void Ready();
    void Shutdown();
    void ProcessInput();

    void Update();
    void Draw();

private:
    SDL_Window *mWindow = nullptr;
    SDL_Renderer *mRenderer = nullptr;

    bool b_IsRunning = true;

    std::vector<std::unique_ptr<GameObject>> mGameObjects;
};
