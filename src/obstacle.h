#pragma once

#include "player.h"

namespace flappyBird
{

	struct Obstacle
	{

		float positionX;
		float positionY;
		float speedX;
		float sizeY;
		float sizeX;
		bool passed;
	};

	void startObstacle(Obstacle& obstacle, Obstacle& obstacle2, int screenWidth, int screenHeight);
	void obstacleMovement(Obstacle& obstacle, Obstacle& obstacle2, const int screenWidth, const int screenHeight);
	bool colisionCheck(Obstacle obstacle, Obstacle obstacle2, Player player);
	void addPoints(Obstacle& obstacle, Player& player1, Player& player2);

}