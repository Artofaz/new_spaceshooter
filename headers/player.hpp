#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include <vector>


class Player{

    public:
        Player() = default;
        Player(SDL_Renderer *renderer, SDL_Surface *img, bool *menu);
        ~Player();

        void updateX(float x), updateY(float y);
        float getDirX(), getDirY();
        float getPosX(), getPosY();

        void updatePlayer(SDL_Renderer *renderer);
        void updateBullets(SDL_Renderer *renderer);

        std::vector<SDL_FRect>* getBullets();

        void shoot();

        void destroyPlayer(SDL_Renderer *renderer);

    private:
        SDL_Texture *playerTx;
        SDL_FRect playerRect;
        float dirX, dirY;
        float speed;
        std::vector<SDL_FRect> bullets;
        bool *menu;
};
#endif
