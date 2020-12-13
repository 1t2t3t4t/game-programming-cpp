#pragma once
#include "Vector2.h"

class SDL_Window;
class SDL_Renderer;

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

    SDL_Window *mWindow = nullptr;
    SDL_Renderer *mRenderer = nullptr;
    bool mIsRunning = true;

    Vector2 mPaddle { 20, 300 };
    Vector2 mBall { 400, 300 };
};
