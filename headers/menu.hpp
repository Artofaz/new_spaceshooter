#pragma once
#ifndef MENU_HPP
#define MENU_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Menu{
    public:
        Menu(SDL_Renderer *renderer, SDL_Window *window);
        ~Menu();

        void showMenu();
        void quitMenu();
    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
};

#endif