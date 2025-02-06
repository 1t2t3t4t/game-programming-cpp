#pragma once

class SDL_Window;

class Game
{
public:
    Game() = default;
    ~Game();

    bool Init();
    void RunLoop();

private:
    void Shutdown();

private:
    SDL_Window* mWindow = nullptr;
    bool b_IsRunning = true;
};
