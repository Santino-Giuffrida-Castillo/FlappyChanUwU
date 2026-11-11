#include "obstacle.h"
#include <iostream>
#include <raylib.h>

void startObstacle(Obstacle& obstacle, Obstacle& obstacle2, int screenWidth, int screenHeight)
{
	//obstáculo superior
	obstacle.sizeX = 50;
	obstacle.sizeY = static_cast<float>( rand() % (screenHeight / 2) + (screenHeight / 8) );
	obstacle.positionX = static_cast<float>(screenWidth);
	obstacle.positionY = 0;
	obstacle.speedX = 150;

	//obstáculo inferior
	obstacle2.sizeX = 50;
	obstacle2.positionX = obstacle.positionX;
	obstacle2.positionY = obstacle.sizeY + 300;//para ej juego final dejar en 150 o 200, y hacer una variable a parte
	obstacle2.sizeY = screenHeight - obstacle2.positionY;
	obstacle2.speedX = obstacle.speedX;
}

void obstacleMovement(Obstacle& obstacle, Obstacle& obstacle2, const int screenWidth, const int screenHeight)
{
	// Calculamos cuánto se desplazan durante este frame
	float movement = obstacle.speedX * GetFrameTime();

	obstacle.positionX -= movement;
	obstacle2.positionX = obstacle.positionX;
	if (obstacle.positionX + obstacle.sizeX < 0)
	{
		obstacle.positionX = static_cast<float>(screenWidth);
		obstacle.sizeY = static_cast<float>( rand() % (screenHeight / 2) + (screenHeight / 8) );
		obstacle2.positionY = obstacle.sizeY + 300;//para ej juego final dejar en 150 o 200
		obstacle2.sizeY = screenHeight - obstacle2.positionY;
		std::cout << obstacle.sizeY;
	}
}

bool colisionCheck(Obstacle obstacle, Obstacle obstacle2, Player player)
{
	//Colisión horizontal con el obstáculo superior
	bool colisionX1 = obstacle.positionX + obstacle.sizeX > player.positionX && obstacle.positionX < player.positionX + player.rectangleSize;

	//Colisión vertical con el obstáculo superior
	bool colisionY1 = obstacle.positionY + obstacle.sizeY > player.positionY && obstacle.positionY < player.positionY + player.rectangleSize;

	//Colisión horizontal con el obstáculo inferior
	bool colisionX2 = obstacle2.positionX + obstacle2.sizeX > player.positionX && obstacle2.positionX < player.positionX + player.rectangleSize;

	//Colisión vertical con el obstáculo inferior
	bool colisionY2 = obstacle2.positionY + obstacle2.sizeY > player.positionY && obstacle2.positionY < player.positionY + player.rectangleSize;

	//Si choca con cualquiera de los dos, devuelve true
	return (colisionX1 && colisionY1) || (colisionX2 && colisionY2);
}