#include <explosion.hpp>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Explosion::Explosion(SDL_Renderer *renderer, SDL_Texture *explosionTx, int posX, int posY, int w, int h, int sheetWidth, int sheetHeight){
    animTime = 0;
    SDL_QueryTexture(explosionTx, NULL, NULL, &textureWidth, &textureHeight);
    this->explosionTx = explosionTx;
    frameWidth = textureWidth / sheetWidth;
    frameHeight = textureHeight / sheetHeight;

    explosionRect.x = explosionRect.y = 0;
    explosionRect.w = frameWidth;
    explosionRect.h = frameHeight;
    dstRect.x = posX;
    dstRect.y = posY;
    dstRect.w = w; 
    dstRect.h = h;
};

Explosion::~Explosion(){

};

void Explosion::updateExplosion(SDL_Renderer *renderer, std::vector<Explosion*>* all_explosions, int index){

    SDL_RenderCopy(renderer, explosionTx, &explosionRect, &dstRect);

    animTime++;
    if(60/animTime == 60){ // => FPS/animTime
        animTime = 0;
        explosionRect.x += frameWidth;
        if(explosionRect.x >= textureWidth){
            explosionRect.x = 0;
            explosionRect.y += frameHeight;
            if(explosionRect.y >= textureHeight){ //when explosion done
                delete this;
                all_explosions->erase(all_explosions->begin()+index);
            }
        }
        
    }
};