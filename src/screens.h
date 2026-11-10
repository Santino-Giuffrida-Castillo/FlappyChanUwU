#pragma once
#include "player.h"
#include "obstacle.h"

enum GameScreen
{
	MENU, 
	PLAY, 
	CREDITS, 
	TUTORIAL, 
	EXIT, 
	LOSE 
};

void updateScreens(Player& player, int screenWidth, int screenHeight, Obstacle& obstacle, Obstacle& obstacle2, GameScreen& actualScreen, bool isRunning);
void drawScreens(Player player, int screenWidth, int screenHeight, Obstacle obstacle, Obstacle obstacle2, GameScreen actualScreen);