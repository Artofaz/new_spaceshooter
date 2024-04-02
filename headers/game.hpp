#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <game.hpp>
#include <asteroid.hpp>
#include <explosion.hpp>
#include <player.hpp>
#include <iostream>
#include <utils.hpp>

class Game{

    public:
        Game(SDL_Renderer *renderer, SDL_Window *window);
        ~Game();

        void init();
        void quit();

        void mainLoop(bool *quit);

    private:

        SDL_Window* window;
        SDL_Renderer *renderer;
        SDL_Surface *spaceship;
        SDL_Surface *asteroidSurface;
        SDL_Surface *background;
        SDL_Surface *explosionSheet;
        SDL_Surface *explosionSheetShip;

        SDL_Texture *backgroundTx;
        SDL_Texture *explosionTx;
        SDL_Texture *explosionShipTx;
        SDL_Texture *asteroidTx;

        Player *player;
        std::vector<Asteroid*> all_asteroids;
        std::vector<Explosion*> all_explosions;

        //FRAMES STUFF
        const int FPS = 60;
        const int frameDelay = 1000/FPS;
        Uint32 frameStart;
        int frameTime;

        int asteroidDelay;
        int shootDelay;

        const Uint8* keystates;
        SDL_Scancode ku;
        SDL_Scancode kd;
        SDL_Scancode kr;
        SDL_Scancode kl;

        SDL_Event e;
};

#endif