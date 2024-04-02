#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <menu.hpp>

Menu::Menu(SDL_Renderer *renderer, SDL_Window *window){
    this->renderer = renderer;
    this->window = window;
};
Menu::~Menu(){};

void Menu::showMenu(){
    std::cout << "Showing menu" << std::endl;
};
void Menu::quitMenu(){
    std::cout << "Quitting menu" << std::endl;
    delete this;
    //new Game
};