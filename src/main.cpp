#include <iostream>
#include <Game/Game.h>
#include <SDL3/SDL.h>

int main() {
    std::cout << "Hello World" << std::endl;
    SDL_Init(0);
    SDL_Window* window = SDL_CreateWindow("My Game", 1280, 720, SDL_WINDOW_RESIZABLE);

    if (window == nullptr) 
    {
        printf("Window cannot be init.\n");
    }
    return 0;
}
