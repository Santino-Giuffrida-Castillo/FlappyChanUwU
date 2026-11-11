#include "game.h"
#include <iostream>
#include <raylib.h>

namespace flappyBird
{

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


	void startGame(Player& player1, Player& player2, Obstacle& obstacle, Obstacle& obstacle2, ParallaxBackground& backGround)
	{

		float margin = screenWidth * 0.05f;

		player1.positionX = margin;
		player1.rectangleSize = 50;
		player1.positionY = (screenHeight / 2) - (player1.rectangleSize / 2);

		player1.points = 0;
		player1.speedY = 0;
		player1.gravity = 300;
		player1.flappForce = -200;

		player2.positionX = margin + 50;
		player2.rectangleSize = 50;
		player2.positionY = (screenHeight / 2) - (player2.rectangleSize / 2);

		player2.points = 0;
		player2.speedY = 0;
		player2.gravity = 300;
		player2.flappForce = -200;

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

		Player player1;
		Player player2;
		player2.isActive = false;

		Obstacle obstacle;
		Obstacle obstacle2;
		GameScreen actualScreen = MENU;
		ParallaxBackground backGround;

		startGame(player1, player2, obstacle, obstacle2, backGround);

		while (!WindowShouldClose() && actualScreen != EXIT)
		{

			updateScreens(player1, player2, obstacle, obstacle2, actualScreen, backGround);
			//dibujado

			BeginDrawing();

			ClearBackground(BLACK);

			drawScreens(player1, player2, obstacle, obstacle2, actualScreen, backGround);

			//version
			DrawText("V0.3", 0, 0, 20, WHITE);

			EndDrawing();

		}

		CloseWindow();

	}
}