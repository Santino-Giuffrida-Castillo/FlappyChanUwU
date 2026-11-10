#include "game.h"
#include <iostream>
#include <raylib.h>

void loseConditions(const Obstacle& obstacle, const Obstacle& obstacle2, Player& player, GameScreen& actualScreen)
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


void startGame(Player& player, Obstacle& obstacle, Obstacle& obstacle2, ParallaxBackground& backGround)
{
	float margin = screenWidth * 0.05f;

	player.positionX = margin;
	player.rectangleSize = 50;
	player.positionY = (screenHeight / 2) - (player.rectangleSize / 2);

	player.points = 0;
	player.speedY = 0;
	player.gravity = 300;
	player.flappForce = -200;

	backGround.back = LoadTexture("res/back.png");
	backGround.mid = LoadTexture("res/middle.png");
	backGround.front = LoadTexture("res/front.png");
	startObstacle(obstacle, obstacle2, screenWidth, screenHeight);

}

void run()
{
	srand(static_cast<unsigned int>(time(0)));


	InitWindow(screenWidth, screenHeight, "Flappy Chan UwU");
	SetExitKey(KEY_NULL);

	Player player;
	Obstacle obstacle;
	Obstacle obstacle2;
	GameScreen actualScreen = MENU;
	ParallaxBackground backGround;

	startGame(player, obstacle, obstacle2, backGround);

	while (!WindowShouldClose() && actualScreen != EXIT)
	{
		updateScreens(player, obstacle, obstacle2, actualScreen, backGround);
		//dibujado

		BeginDrawing();

		ClearBackground(BLACK);

		drawScreens(player, obstacle, obstacle2, actualScreen, backGround);

		//version
		DrawText("V0.3", 0, 0, 20, WHITE);

		EndDrawing();
	}
	CloseWindow();
}