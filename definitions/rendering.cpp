#include <rendering.hpp>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Rendering::Rendering(){};
Rendering::~Rendering(){};

void Rendering::initRendering(){
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("Spaceshooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    if(window == NULL){
        std::cout << "Error creating window" << std::endl;
        SDL_Quit();
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL){
        std::cout << "Error creating renderer" << std::endl;
        SDL_Quit();
        return;
    }
};

void Rendering::quitRendering(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
};

SDL_Renderer *Rendering::getRenderer(){
    return renderer;
};
SDL_Window* Rendering::getWindow(){
    return window;
};