#pragma once

class SDL_Window;

class Game final
{
public:
    const bool Initialize();
    void RunLoop();
    void ShutDown();

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    SDL_Window* mWindow = nullptr;
    bool mIsRunning = true;
};
