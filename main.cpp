#include <iostream>
#include <Game/Game.h>
#include <SDL2/SDL.h>

int main() {
    std::cout << "Hello World" << std::endl;
    Game g;
    g.SayHello();
    SDL_Init(0);
    return 0;
}
