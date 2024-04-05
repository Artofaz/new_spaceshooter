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

    bool quit = false;
    bool menu = true;
    Game *game = new Game(rendering.getRenderer(), rendering.getWindow());
    game->init(&quit, &menu);

    while(!quit){ 
        if(menu) game->showMenu();
        else game->mainLoop();
    }
    game->quitGame();
    rendering.quitRendering();

    return 0;
}