#pragma once

#include "Vector2.h"
#include <SDL2/SDL.h>

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
    Uint32 mPrevTickTime = 0;

    Vector2 mPaddle { 20, 300 };
    Vector2 mBall { 400, 300 };

    int mPaddleDir = 0;
};
