#include "Game.h"

#include <algorithm>
#include <SDL2/SDL.h>

#pragma region Public

const int WallThickness = 20;

const bool Game::Initialize()
{
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("Cpp Game Programming", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!mWindow)
    {
        SDL_Log("Unable to create SDL Windows: %s", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!mRenderer)
    {
        SDL_Log("Failed to create renderer %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ShutDown()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

#pragma endregion

#pragma region Private
 
void Game::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type) 
        {
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }

    const Uint8 *keyboardStates = SDL_GetKeyboardState(nullptr);
    if (keyboardStates[SDL_SCANCODE_ESCAPE])
    {
        mIsRunning = false;
    }
}

void Game::UpdateGame()
{
    const Uint32 currentTick = SDL_GetTicks();
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), currentTick + 16))
        ;

    float deltaTime = (currentTick - mPrevTickTime) / 1000.f;
    mPrevTickTime = currentTick;
    deltaTime = std::clamp(deltaTime, 0.f, .05f);

    SDL_Log("Delta Time %f", deltaTime);
}

void Game::GenerateOutput()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
    SDL_RenderClear(mRenderer);
    
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

    const SDL_Rect wall { 0, 0, 800, WallThickness };
    SDL_RenderFillRect(mRenderer, &wall);

    const SDL_Rect ball{
        static_cast<int>(mBall.x - 10 / 2),
        static_cast<int>(mBall.y - 10 / 2),
        10,
        10};
    SDL_RenderFillRect(mRenderer, &ball);
    const SDL_Rect paddle{
        static_cast<int>(mPaddle.x - 10 / 2),
        static_cast<int>(mPaddle.y - 80 / 2),
        10,
        80};
    SDL_RenderFillRect(mRenderer, &paddle);

    SDL_RenderPresent(mRenderer);
}

#pragma endregion 