#pragma once
#include "player.h"
#include "obstacle.h"
#include "background.h"

enum GameScreen
{
	MENU, 
	PLAY, 
	CREDITS, 
	TUTORIAL, 
	EXIT, 
	LOSE 
};

const int screenWidth = 1080;
const int screenHeight = 720;

void updateScreens(Player& player ,Obstacle& obstacle, Obstacle& obstacle2, GameScreen& actualScreen, ParallaxBackground& backGround);
void drawScreens(Player player, Obstacle obstacle, Obstacle obstacle2, GameScreen actualScreen, ParallaxBackground& backGround);