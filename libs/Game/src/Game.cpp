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

    mRenderer = SDL_CreateRenderer(mWindow, nullptr);
    if (mRenderer == nullptr)
    {
        SDL_Log("SDL couldn't create renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::RunLoop()
{
    while (b_IsRunning)
    {
        ProcessInput();

        // Clear Back Buffer
        SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
        SDL_RenderClear(mRenderer);

        // Swap Back Buffer with Front Buffer
        SDL_RenderPresent(mRenderer);
    }
}

void Game::Shutdown()
{
    SDL_Log("Game is shutting down");
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
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
