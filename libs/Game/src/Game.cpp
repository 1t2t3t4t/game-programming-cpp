#include "SDL3/SDL_log.h"
#include <Game/Game.h>
#include <SDL3/SDL.h>

Game::~Game()
{
    Shutdown();
}

bool Game::Init()
{
    bool result = SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);
    if (!result)
    {
        SDL_Log("SDL init error: %s", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("Game", 1280, 720, SDL_WINDOW_RESIZABLE);
    if (mWindow == nullptr)
    {
        SDL_Log("SDL couldn't create window: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::RunLoop()
{
    while (b_IsRunning)
    {
    }
}

void Game::Shutdown()
{
    SDL_Log("Game is shutting down");
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}
