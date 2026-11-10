#include <iostream>
#include <cstdlib>
#include <ctime>
#include "obstacle.h"
#include "player.h"
#include "screens.h"
#include "raylib.h"
#include "game.h"

//separar los archivos y arreglar el desastre de las funciones
//hacer bien el menu y los creditos
//poner tags
//ver como se ponen tags
//preparar release sin consola
//buscar fondos para aprovechar el paralax

//issues
//revisar issues
//la perdida manda al menu

using namespace std;

int main()
{
	srand(time(0));

	const int screenWidth = 1080;
	const int screenHeight = 720;

	bool isRunning = true;
	InitWindow(screenWidth, screenHeight, "Flappy Chan UwU");
	SetExitKey(KEY_NULL);

	Player player;
	Obstacle obstacle;
	Obstacle obstacle2;
	GameScreen actualScreen = MENU;

	int selector;

	startGame(player, screenWidth, screenHeight, obstacle, obstacle2);

	while (!WindowShouldClose() && actualScreen != EXIT)
	{


		if (actualScreen == MENU)
		{
			if (IsKeyPressed(KEY_ONE))
			{
				startGame(player, screenWidth, screenHeight, obstacle, obstacle2);
				actualScreen = PLAY;
			}
			if (IsKeyPressed(KEY_TWO))
			{
				actualScreen = CREDITS;
			}
			if (IsKeyPressed(KEY_THREE))
			{
				actualScreen = TUTORIAL;
			}
			if (IsKeyPressed(KEY_FOUR))
			{
				actualScreen = EXIT;
			}
		}
		else if (actualScreen == CREDITS)
		{
			if (IsKeyPressed(KEY_ESCAPE))
			{
				actualScreen = MENU;
			}
		}
		else if (actualScreen == TUTORIAL)
		{
			if (IsKeyPressed(KEY_ESCAPE))
			{
				actualScreen = MENU;
			}
		}
		else if (actualScreen == LOSE)
		{
			if (IsKeyPressed(KEY_ESCAPE))
			{
				actualScreen = MENU;
			}
			if (IsKeyPressed(KEY_R))
			{
				actualScreen = PLAY;
				startGame(player, screenWidth, screenHeight, obstacle, obstacle2);
			}
		}
		//actualizacion
		else if (actualScreen == PLAY)
		{
			playerMovement(player, screenHeight);
			obstacleMovement(obstacle, obstacle2, screenWidth, screenHeight);
			loseConditions(obstacle, obstacle2, player, isRunning, screenHeight, actualScreen);
			if (IsKeyPressed(KEY_ESCAPE))
			{
				actualScreen = MENU;
			}
		}

		//dibujado

		BeginDrawing();

		ClearBackground(BLACK);


		if (actualScreen == MENU)
		{
			DrawText("FlappuChanUwU", screenWidth / 8, screenHeight * 0.2, 50, WHITE);
			DrawText("1. JUGAR", screenWidth / 8, screenHeight * 0.5, 40, GREEN);
			DrawText("2. CREDITOS", screenWidth / 8, screenHeight * 0.6, 40, YELLOW);
			DrawText("3. TUTORIAL", screenWidth / 8, screenHeight * 0.7, 40, BLUE);
			DrawText("4. SALIR", screenWidth / 8, screenHeight * 0.8, 40, RED);
		}
		else if (actualScreen == PLAY)
		{
			//jugador
			DrawRectangle(player.positionX, player.positionY, player.rectangleSize, player.rectangleSize, PURPLE);

			//obstáculo superior
			DrawRectangle(obstacle.positionX, obstacle.positionY, obstacle.sizeX, obstacle.sizeY, WHITE);

			//obstáculo inferior
			DrawRectangle(obstacle2.positionX, obstacle2.positionY, obstacle2.sizeX, obstacle2.sizeY, WHITE);
		}
		else if (actualScreen == CREDITS)
		{
			DrawText("DESARROLLADOR", screenWidth / 8, screenHeight * 0.4, 50, WHITE);
			DrawText("Manaos_ChanUwU", screenWidth / 8, screenHeight * 0.5, 70, VIOLET);
			DrawText("ESCAPE para volver al menu", screenWidth / 8, screenHeight * 0.65, 40, WHITE);
		}
		else if (actualScreen == TUTORIAL)
		{
			DrawText("W para saltar", screenWidth / 8, screenHeight * 0.4, 40, WHITE);
			DrawText("ESCAPE para volver al menu", screenWidth / 8, screenHeight * 0.5, 40, WHITE);
			DrawText("(aca tambien funciona)", screenWidth / 8, screenHeight * 0.55, 30, WHITE);
			DrawText("Q para pausa", screenWidth / 8, screenHeight * 0.6, 40, WHITE);
		}
		else if (actualScreen == LOSE)
		{
			DrawText("puntaje", screenWidth / 8, screenHeight * 0.3, 50, WHITE);
			DrawText("R para reintentar", screenWidth / 8, screenHeight * 0.4, 40, WHITE);
			DrawText("ESCAPE para volver al menu", screenWidth / 8, screenHeight * 0.5, 40, WHITE);
		}

		//version
		DrawText("V0.2", 0, 0, 20, WHITE);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}

