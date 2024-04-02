#include <asteroid.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

Asteroid::Asteroid(SDL_Renderer *renderer, SDL_Texture *asteroidTx){
    angle = 0;
    srand (time(NULL));
    
    this->asteroidTx = asteroidTx;

    dirX = ( (rand() % 200) + 100 )/100;
    dirY = ( (rand() % 300) + 250)/100;

    int part = ( rand()%600 + 1);
    if(part > 300){
        dirX *= -1;
    }

    speed = 1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.5)));


    int randNum = rand()%64 + 48;
    asteroidRect.x = part;
    asteroidRect.y = -64;
    asteroidRect.w = randNum;
    asteroidRect.h = randNum;
}

Asteroid::~Asteroid(){};

void Asteroid::updateAsteroid(SDL_Renderer *renderer, std::vector<Asteroid*>* all_asteroids, int index){
    angle += 5;
    asteroidRect.x += dirX*speed;
    asteroidRect.y += dirY*speed;

    SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyExF(renderer, asteroidTx, NULL, &asteroidRect, angle, NULL, flip);

    if(asteroidRect.y > 600){
        this->destroyAsteroid(renderer, all_asteroids, index);
    }
    else if(asteroidRect.x > 600){
        this->destroyAsteroid(renderer, all_asteroids, index);
    }

    
};

void Asteroid::destroyAsteroid(SDL_Renderer *renderer, std::vector<Asteroid*>* all_asteroids, int index){
    delete this;
    all_asteroids->erase(all_asteroids->begin()+index);
};


float Asteroid::getPosX(){
    return asteroidRect.x;
};

float Asteroid::getPosY(){
    return asteroidRect.y;
};

float Asteroid::getHeight(){
    return asteroidRect.h;
};

float Asteroid::getWidth(){
    return asteroidRect.w;
};