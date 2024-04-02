#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <game.hpp>
#include <rendering.hpp>
#include <menu.hpp>

using namespace std;

int main(int argc, char *argv[]){

    Rendering rendering = Rendering();
    rendering.initRendering();

    Game *game = new Game(rendering.getRenderer(), rendering.getWindow());
    game->init();

    bool quit = false;
    while(!quit){ 
        game->mainLoop(&quit);
    }
    game->quit();
    rendering.quitRendering();

    return 0;
}