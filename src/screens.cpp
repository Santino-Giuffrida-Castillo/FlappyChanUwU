#include "screens.h"
#include "game.h"
#include <raylib.h>

void updateScreens(Player& player, Obstacle& obstacle, Obstacle& obstacle2, GameScreen& actualScreen, ParallaxBackground& backGround)
{
	if (actualScreen == MENU)
	{
		if (IsKeyPressed(KEY_ONE))
		{
			startGame(player, obstacle, obstacle2, backGround);
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
			startGame(player, obstacle, obstacle2, backGround);
		}
	}
	//actualizacion
	else if (actualScreen == PLAY)
	{
		playerMovement(player, screenHeight);
		obstacleMovement(obstacle, obstacle2, screenWidth, screenHeight);
		loseConditions(obstacle, obstacle2, player, actualScreen);
		updateParallax(backGround);

		if (IsKeyPressed(KEY_ESCAPE))
		{
			actualScreen = MENU;
		}
	}
}
void drawScreens(Player player,Obstacle obstacle, Obstacle obstacle2, GameScreen actualScreen, ParallaxBackground& backGround)
{

	if (actualScreen == MENU)
	{
		DrawText("FlappuChanUwU", screenWidth / 8, static_cast <int>(screenHeight * 0.2), 50, WHITE);
		DrawText("1. JUGAR", screenWidth / 8, static_cast <int>(screenHeight * 0.5), 40, GREEN);
		DrawText("2. CREDITOS", screenWidth / 8, static_cast <int>(screenHeight * 0.6), 40, YELLOW);
		DrawText("3. TUTORIAL", screenWidth / 8, static_cast <int>(screenHeight * 0.7), 40, BLUE);
		DrawText("4. SALIR", screenWidth / 8, static_cast <int>(screenHeight * 0.8), 40, RED);
	}
	else if (actualScreen == PLAY)
	{
		drawParallax(backGround);
		//jugador
		DrawRectangle(static_cast<int>(player.positionX), static_cast<int>(player.positionY), static_cast<int>(player.rectangleSize), static_cast<int>(player.rectangleSize), PURPLE);

		//obstáculo superior
		DrawRectangle(static_cast<int>(obstacle.positionX), static_cast<int>(obstacle.positionY), static_cast<int>(obstacle.sizeX), static_cast<int>(obstacle.sizeY), WHITE);

		//obstáculo inferior
		DrawRectangle(static_cast<int>(obstacle2.positionX), static_cast<int>(obstacle2.positionY), static_cast<int>(obstacle2.sizeX), static_cast<int>(obstacle2.sizeY), WHITE);

		
	}
	else if (actualScreen == CREDITS)
	{
		DrawText("DESARROLLADOR", screenWidth / 8, static_cast <int>(screenHeight * 0.4), 50, WHITE);
		DrawText("Manaos_ChanUwU", screenWidth / 8, static_cast <int>(screenHeight * 0.5), 70, VIOLET);
		DrawText("ESCAPE para volver al menu", screenWidth / 8, static_cast <int>(screenHeight * 0.65), 40, WHITE);
	}
	else if (actualScreen == TUTORIAL)
	{
		DrawText("W para saltar", screenWidth / 8, static_cast <int>(screenHeight * 0.4), 40, WHITE);
		DrawText("ESCAPE para volver al menu", screenWidth / 8, static_cast <int>(screenHeight * 0.5), 40, WHITE);
		DrawText("(aca tambien funciona)", screenWidth / 8, static_cast <int>(screenHeight * 0.55), 30, WHITE);
		DrawText("Q para pausa", screenWidth / 8, static_cast <int>(screenHeight * 0.6), 40, WHITE);
	}
	else if (actualScreen == LOSE)
	{
		DrawText("puntaje", screenWidth / 8, static_cast <int>(screenHeight * 0.3), 50, WHITE);
		DrawText("R para reintentar", screenWidth / 8, static_cast <int>(screenHeight *  0.4), 40, WHITE);
		DrawText("ESCAPE para volver al menu", screenWidth / 8, static_cast <int>(screenHeight * 0.5), 40, WHITE);
	}
}