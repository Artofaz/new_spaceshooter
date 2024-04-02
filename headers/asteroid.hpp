#pragma once
#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>


class Asteroid{
    public:
        Asteroid() = default;
        Asteroid(SDL_Renderer *renderer, SDL_Texture *asteroidTx);
        ~Asteroid();

        float getPosX(), getPosY();
        float getHeight(), getWidth();

        void updateAsteroid(SDL_Renderer *renderer, std::vector<Asteroid*>* all_asteroids, int index);
        void destroyAsteroid(SDL_Renderer *renderer, std::vector<Asteroid*>* all_asteroids, int index);
    private:
        SDL_Texture *asteroidTx;
        SDL_FRect asteroidRect;
        float dirX, dirY;
        int angle;
        float speed;
};

#endif
