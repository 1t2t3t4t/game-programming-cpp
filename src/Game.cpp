#include "Game.h"
#include <SDL2/SDL.h>

#pragma region Public 

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
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

#pragma endregion

#pragma region Private
 
void Game::ProcessInput()
{

}

void Game::UpdateGame()
{

}

void Game::GenerateOutput()
{
    
}

#pragma endregion 