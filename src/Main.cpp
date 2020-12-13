#include <iostream>
#include "Game.h"

int main()
{
    Game game;
    const bool initSuccess = game.Initialize();
    if (initSuccess)
    {
        game.RunLoop();
    }
    game.ShutDown();
    return 0;
}