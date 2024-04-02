#pragma once 
#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class Explosion{

    public:
        Explosion() = default;
        Explosion(SDL_Renderer *renderer, SDL_Texture *explosionTx, int posX, int posY, int w, int h, int sheetWidth, int sheetHeight);
        ~Explosion();

        void updateExplosion(SDL_Renderer *renderer, std::vector<Explosion*>* all_explosions, int index);

    private:
        SDL_Texture *explosionTx;
        int animTime;
        SDL_Rect explosionRect;
        SDL_Rect dstRect;
        int frameWidth, frameHeight;
        int textureWidth, textureHeight;
};

#endif