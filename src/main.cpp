#include <Game/Game.h>
#include <cstdio>

int main() {
    Game game;
    if (!game.Init())
    {
        return 1;
    }


    printf("Done\n");
    return 0;
}
