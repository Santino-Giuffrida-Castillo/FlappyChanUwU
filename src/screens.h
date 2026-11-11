#pragma once
#include "player.h"
#include "obstacle.h"
#include "background.h"

namespace flappyBird
{

	enum GameScreen
	{
		MENU,
		PLAY,
		CREDITS,
		TUTORIAL,
		OPTIONS,
		EXIT,
		LOSE
	};

	const int screenWidth = 1080;
	const int screenHeight = 720;

	void updateScreens(Player& player, Player& player2, Obstacle& obstacle, Obstacle& obstacle2, GameScreen& actualScreen, ParallaxBackground& backGround);
	void drawScreens(Player player1, Player player2, Obstacle obstacle, Obstacle obstacle2, GameScreen actualScreen, ParallaxBackground& backGround);

}