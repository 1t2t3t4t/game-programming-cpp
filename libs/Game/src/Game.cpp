#include <Game/Game.h>
#include <SDL3/SDL.h>
#include "Wall.h"

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

    mRenderer = SDL_CreateRenderer(mWindow, nullptr);
    if (mRenderer == nullptr)
    {
        SDL_Log("SDL couldn't create renderer: %s", SDL_GetError());
        return false;
    }

    Wall w({{1, 2}, {3, 4}});
    w.Update();
    mGameObjects.push_back(&w);
    return true;
}

void Game::RunLoop()
{
    while (b_IsRunning)
    {
        ProcessInput();

        Update();

        // Clear Back Buffer
        SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0);
        SDL_RenderClear(mRenderer);

        Draw();

        // Swap Back Buffer with Front Buffer
        SDL_RenderPresent(mRenderer);
    }
}

void Game::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            b_IsRunning = false;
            break;
        }
    }

    auto keyboardState = SDL_GetKeyboardState(nullptr);
    if (keyboardState[SDL_SCANCODE_ESCAPE])
    {
        b_IsRunning = false;
    }
}

void Game::Update()
{
    for (auto object : mGameObjects)
    {
        object->Update();
    }
}

void Game::Draw()
{
    for (auto object : mGameObjects)
    {
        object->Draw();
    }
}

void Game::Shutdown()
{
    SDL_Log("Game is shutting down");
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}
