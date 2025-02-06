#include <Game/Game.h>
#include <SDL3/SDL.h>

int main()
{
    Game game;
    if (!game.Init())
    {
        return 1;
    }

    game.RunLoop();

    return 0;
}
