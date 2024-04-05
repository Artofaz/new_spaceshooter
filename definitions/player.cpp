#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <player.hpp>
#include <cmath>
#include <iostream>
#include <vector>


Player::Player(SDL_Renderer *renderer, SDL_Surface *img, bool *menu){

    this->menu = menu;

    playerTx = SDL_CreateTextureFromSurface(renderer, img);

    playerRect.x = 300.0;
    playerRect.y = 568.0;
    playerRect.w = 32.0;
    playerRect.h = 32.0;
    speed = 6.5;
    dirX = 0;
    dirY = 0;
};
Player::~Player(){
    SDL_DestroyTexture(playerTx);
    *menu = false;
};

void Player::updateX(float x){
    dirX = x;
};

void Player::updateY(float y){
    dirY = y;
};

float Player::getDirX(){
    return dirX;
}

float Player::getDirY(){
    return dirY;
}

float Player::getPosX(){
    return playerRect.x;
}

float Player::getPosY(){
    return playerRect.y;
}

void Player::updatePlayer(SDL_Renderer *renderer){
    float magnitude = sqrt( pow(dirX, (float)2.0)+pow(dirY, (float)2.0) );
    if(magnitude == 0) magnitude = 1;
    playerRect.x += dirX/magnitude * speed;
    playerRect.y += dirY/magnitude *speed;

    if(playerRect.x + 32 < 0) playerRect.x = 600;
    else if(playerRect.x > 600) playerRect.x = -32;

    if(playerRect.y + 32 >= 600) playerRect.y = 568;
    else if(playerRect.y <= 0) playerRect.y = 0;

    SDL_RenderCopyF(renderer, playerTx, NULL, &playerRect);
};

void Player::updateBullets(SDL_Renderer *renderer){
    for(int i = 0; i < (int)bullets.size(); i++){
        bullets.at(i).y -= 10;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRectF(renderer, &bullets.at(i));
        if(bullets.at(i).y < 0) bullets.erase(bullets.begin()+i);
    }
};

void Player::shoot(){

    SDL_FRect bullet;
    bullet.x = playerRect.x;
    bullet.y = playerRect.y;

    bullet.w = 5;
    bullet.h = 7;

    bullets.push_back(bullet);
};

std::vector<SDL_FRect>* Player::getBullets(){
    return &bullets;
};

void Player::destroyPlayer(SDL_Renderer *renderer){
    std::cout << "Player destroyed" << std::endl;
    delete this;
};