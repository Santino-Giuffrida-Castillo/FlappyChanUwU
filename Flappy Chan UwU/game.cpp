#include "game.h"
#include <iostream>

void loseConditions(const Obstacle& obstacle, const Obstacle& obstacle2, Player& player, bool& isRunning, const int screenHeight, GameScreen& actualScreen)
{
	//colisiones
	if (colisionCheck(obstacle, obstacle2, player))
	{
		std::cout << "Acontecio una colision" << std::endl;
		//se pausa
		//R para reiniciar
		//ESC para volver al menu
		actualScreen = LOSE;
	}
	//piso
	if (player.positionY > screenHeight)
	{
		std::cout << "Perdiste: tocaste el suelo" << std::endl;
		actualScreen = LOSE;
	}
}


void startGame(Player& player, int screenWidth, int screenHeight, Obstacle& obstacle, Obstacle& obstacle2)
{
	float margin = screenWidth * 0.05f;

	player.positionX = margin;
	player.rectangleSize = 50;
	player.positionY = (screenHeight / 2) - (player.rectangleSize / 2);

	player.points = 0;
	player.speedY = 0;
	player.gravity = 300;
	player.flappForce = -200;

	startObstacle(obstacle, obstacle2, screenWidth, screenHeight);

}