#include "Game.h"
#include "Actor.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SpriteComponent.h"

#pragma region Public

bool Game::Initialize()
{
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);

    if (sdlResult != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    const int imgResult = IMG_Init(IMG_INIT_PNG);
    if (imgResult == 0)
    {
        SDL_Log("Unable to initialize SDL image: %s", IMG_GetError());
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
    const float deltaTime = (SDL_GetTicks() - tickCount) / 1000.f;
    tickCount = SDL_GetTicks();

    mIsUpdate = true;
    for (auto actor : mActors)
    {
        actor->Update(deltaTime);
    }
    mIsUpdate = false;

    for (auto pending : mPendingAddActors)
    {
        mActors.emplace_back(pending);
    }
    mPendingAddActors.clear();

    std::vector<Actor*> deadActors;
    for (auto actor : mActors)
    {
        if (actor->GetState() == State::Dead)
        {
            deadActors.emplace_back(actor);
        }
    }

    for (auto dead : deadActors)
    {
        delete dead;
    }
}

void Game::GenerateOutput()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
    SDL_RenderClear(mRenderer);

    SDL_RenderPresent(mRenderer);
}

void Game::AddActor(Actor *actor)
{
    if (mIsUpdate)
    {
        mPendingAddActors.emplace_back(actor);
    }
    else
    {
        mActors.emplace_back(actor);
    }
}

void Game::RemoveActor(Actor *actor)
{

}

void Game::AddSprite(SpriteComponent *component)
{
    uint32_t insertIdx = 0;
    for (uint32_t i = 0; i <= mDrawOrders.size(); i++)
    {
        if (mDrawOrders[i]->GetDrawOrder() > component->GetDrawOrder())
        {
            insertIdx = i;
            break;
        }
    }

    mDrawOrders.insert(mDrawOrders.begin() + insertIdx, component);
}

#pragma endregion 