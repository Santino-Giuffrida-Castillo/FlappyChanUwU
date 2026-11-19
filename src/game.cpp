#include "game.h"

#include <iostream>

#include "raylib.h"

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
			PlaySound(player.deadSound);
			playMenuMusic();
			actualScreen = LOSE;
		}
		//piso
		if (player.positionY > screenHeight)
		{
			std::cout << "Perdiste: tocaste el suelo" << std::endl;
			PlaySound(player.deadSound);
			playMenuMusic();
			actualScreen = LOSE;
		}
	}


	void startGame(Player& player1, Player& player2, Obstacle& obstacle, Obstacle& obstacle2)
	{

		float margin = screenWidth * 0.05f;

		player1.positionX = margin;
		player1.rectangleSize = 50;
		player1.positionY = (screenHeight / 2) - (player1.rectangleSize / 2);

		player1.points = 0;
		player1.speedY = 0;
		player1.gravity = 300;
		player1.flappForce = -200;

		player1.dest = {
	player1.positionX,
	player1.positionY,
	player1.rectangleSize,
	player1.rectangleSize
		};

		player1.source = {
	0.0f,
	0.0f,
	static_cast<float>(player1.texture.width),
	static_cast<float>(player1.texture.height)
		};

		player1.origin = { 0.0f, 0.0f };

		player2.positionX = margin + 50;
		player2.rectangleSize = 50;
		player2.positionY = (screenHeight / 2) - (player2.rectangleSize / 2);

		player2.points = 0;
		player2.speedY = 0;
		player2.gravity = 300;
		player2.flappForce = -200;

		player2.dest = {
player2.positionX,
player2.positionY,
player2.rectangleSize,
player2.rectangleSize
		};

		player2.source = {
	0.0f,
	0.0f,
	static_cast<float>(player2.texture.width),
	static_cast<float>(player2.texture.height)
		};
		
		player2.origin = { 0.0f, 0.0f };

		playInitSound();

		startObstacle(obstacle, obstacle2, screenWidth, screenHeight);

	}

	void run()
	{

		srand(static_cast<unsigned int>(time(0)));


		InitWindow(screenWidth, screenHeight, "Flappy Chan UwU");
		InitAudioDevice();
		loadGameAudio();
		SetExitKey(KEY_NULL);

		Player player1;
		Player player2;
		player2.isActive = false;

		Obstacle obstacle;
		Obstacle obstacle2;
		GameScreen actualScreen = MENU;
		ParallaxBackground backGround;
		loadBackground(backGround);
		loadPlayerAssets();
		assignPlayerAssets(player1);
		assignPlayerAssets(player2);
		int fontSize = 20;
		int textWidth = MeasureText("V1.0", fontSize);

		playMenuMusic();
		while (!WindowShouldClose() && actualScreen != EXIT)
		{
			updateGameMusic(actualScreen == PLAY);
			
			updateScreens(player1, player2, obstacle, obstacle2, actualScreen, backGround);
			//dibujado

			BeginDrawing();

			ClearBackground(BLACK);

			drawScreens(player1, player2, obstacle, obstacle2, actualScreen, backGround);


			DrawText("V1.0", screenWidth - textWidth - 15, screenHeight - fontSize - 10, fontSize, Fade(WHITE, 0.6f));
			

			EndDrawing();

		}
		unloadBackground(backGround);
		unloadPlayerAssets();
		unloadGameAudio();
		CloseAudioDevice();
		CloseWindow();

	}

}