#pragma once
#ifndef RENDERING_HPP
#define RENDERING_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Rendering{
    public:
        Rendering();
        ~Rendering();

        void initRendering();
        void quitRendering();

        SDL_Renderer *getRenderer();
        SDL_Window *getWindow();

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
};

#endif