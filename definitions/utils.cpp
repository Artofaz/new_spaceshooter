#include <utils.hpp>
#include <iostream>
#include <player.hpp>
#include <asteroid.hpp>
#include <explosion.hpp>
#include <SDL2/SDL.h>
#include <vector>

void checkCollisions(SDL_Renderer *renderer, SDL_Texture *explosionTx, Asteroid *asteroid, Player *player, std::vector<Explosion*>* all_explosions){
    float posX = player->getPosX(), posY = player->getPosY();
    float astX = asteroid->getPosX(), astY = asteroid->getPosY();
    float astW = asteroid->getWidth(), astH = asteroid->getHeight();

    if(astY <= posY && (astY + astH) >= posY && astX <= posX && (astX + astW) >= posX){
        all_explosions->push_back(new Explosion(renderer, explosionTx, (int)posX-48, (int)posY-48, 128, 128, 8, 8));
        player->destroyPlayer(renderer);
    }
}

void checkHits(SDL_Renderer *renderer, SDL_Texture *explosionTx, std::vector<Asteroid*>* all_asteroids, std::vector<SDL_FRect>* bullets, std::vector<Explosion*>* all_explosions){
    for(int i = 0; i < (int)bullets->size(); i++){
        float bulletX = bullets->at(i).x;
        float bulletY = bullets->at(i).y;
        for(int j = 0; j < (int)all_asteroids->size(); j++){
            float astX = all_asteroids->at(j)->getPosX(), astY = all_asteroids->at(j)->getPosY();
            float astW = all_asteroids->at(j)->getWidth(), astH = all_asteroids->at(j)->getHeight();
            if(bulletY+20 >= astY && bulletY+20 <= ( astY + astW) && bulletX >= astX && bulletX <= ( astX + astH)){
                all_asteroids->at(j)->destroyAsteroid(renderer, all_asteroids, j);
                bullets->erase(bullets->begin()+i);
                all_explosions->push_back(new Explosion(renderer, explosionTx, (int)astX, (int)astY, (int)astW, (int)astH, 8, 4));
            }
        }
    }
};
