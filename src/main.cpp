#include <Game/Game.h>

int main() {
    Game game;
    if (!game.Init())
    {
        return 1;
    }

    game.RunLoop();

    return 0;
}
