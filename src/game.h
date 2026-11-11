#pragma once
#include "obstacle.h"
#include "player.h"
#include "screens.h"
#include "background.h"

namespace flappyBird
{
	void loseConditions(const Obstacle& obstacle, const Obstacle& obstacle2, Player& player, GameScreen& actualScreen);
	bool colisionCheck(Obstacle obstacle, Obstacle obstacle2, Player player);
	void startGame(Player& player1, Player& player2, Obstacle& obstacle, Obstacle& obstacle2, ParallaxBackground& backGround);
	void run();
}