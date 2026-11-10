#pragma once
#include "obstacle.h"
#include "player.h"
#include "screens.h"


void loseConditions(const Obstacle& obstacle, const Obstacle& obstacle2, Player& player, const int screenHeight, GameScreen& actualScreen);
bool colisionCheck(Obstacle obstacle, Obstacle obstacle2, Player player);
void startGame(Player& player, int screenWidth, int screenHeight, Obstacle& obstacle, Obstacle& obstacle2);
void run();