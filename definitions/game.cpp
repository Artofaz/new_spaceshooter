#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <game.hpp>
#include <asteroid.hpp>
#include <explosion.hpp>
#include <player.hpp>
#include <iostream>
#include <utils.hpp>

Game::Game(SDL_Renderer *renderer, SDL_Window *window){
    this->renderer = renderer;
    this->window = window;
};

Game::~Game(){};

void Game::init(){

    spaceship =  IMG_Load("./assets/spaceship.png");
    asteroidSurface = IMG_Load("./assets/asteroid.png");
    background = IMG_Load("./assets/spacebg.png");
    explosionSheet = IMG_Load("./assets/explosionFull.png");
    explosionSheetShip = IMG_Load("./assets/shipExplo.png");

    backgroundTx = SDL_CreateTextureFromSurface(renderer, background);
    explosionTx = SDL_CreateTextureFromSurface(renderer, explosionSheet);
    explosionShipTx = SDL_CreateTextureFromSurface(renderer, explosionSheetShip);
    asteroidTx = SDL_CreateTextureFromSurface(renderer, asteroidSurface);

    player = new Player(renderer, spaceship);

    //FRAMES STUFF
    asteroidDelay = 60;
    shootDelay = 0;

    keystates = SDL_GetKeyboardState(NULL);
    ku = SDL_SCANCODE_UP;
    kd = SDL_SCANCODE_DOWN;
    kr = SDL_SCANCODE_RIGHT;
    kl = SDL_SCANCODE_LEFT;
};

void Game::quit(){
    SDL_FreeSurface(spaceship);
    SDL_FreeSurface(asteroidSurface);
    SDL_FreeSurface(explosionSheet);
    SDL_FreeSurface(explosionSheetShip);
    SDL_FreeSurface(background);
    SDL_DestroyTexture(explosionTx);
    SDL_DestroyTexture(asteroidTx);
    SDL_DestroyTexture(explosionShipTx);
    SDL_DestroyTexture(backgroundTx);
    
    delete this;
};

void Game::mainLoop(bool *quit){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTx, NULL, NULL);
        if(shootDelay < 0) shootDelay = 0;
        if(asteroidDelay <= 0){
            all_asteroids.push_back(new Asteroid(renderer, asteroidTx));
            asteroidDelay = 60;
        }
        frameStart = SDL_GetTicks();

        while( SDL_PollEvent( &e ) ){
             if( e.type == SDL_QUIT ) *quit = true;
        }

        if(keystates[kr]){
            player->updateX(1.0);
        }
        else if(keystates[kl]){
            player->updateX(-1.0);
        }
        else{
            player->updateX(0);
        }

        if(keystates[ku]){
            player->updateY(-1.0);
        }
        else if(keystates[kd]){
            player->updateY(1.0);
        }
        else{
            player->updateY(0);
        }

        if(keystates[SDL_SCANCODE_SPACE] && shootDelay <= 0){
            player->shoot();
            shootDelay = 20;
        }

        player->updatePlayer(renderer);
        for(int i = 0; i < (int)all_asteroids.size(); i++){
            all_asteroids.at(i)->updateAsteroid(renderer, &all_asteroids, i);
            checkCollisions(renderer, explosionShipTx, all_asteroids.at(i), player, &all_explosions);
        }
        player->updateBullets(renderer);
        checkHits(renderer, explosionTx, &all_asteroids, player->getBullets(), &all_explosions);
        for(int i = 0; i < (int)all_explosions.size(); i++){
            all_explosions.at(i)->updateExplosion(renderer, &all_explosions, i);
        }

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
        asteroidDelay--;
        shootDelay--;
};