#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <player.hpp>
#include <asteroid.hpp>
#include <explosion.hpp>
#include <SDL2/SDL.h>
#include <vector>

void checkCollisions(SDL_Renderer *renderer, SDL_Texture *explosionTx, Asteroid *asteroid, Player *player, std::vector<Explosion*>* all_explosions);
void checkHits(SDL_Renderer *renderer, SDL_Texture *explosionTx, std::vector<Asteroid*>* all_asteroids, std::vector<SDL_FRect>* bullets, std::vector<Explosion*>* all_explosions);

#endif