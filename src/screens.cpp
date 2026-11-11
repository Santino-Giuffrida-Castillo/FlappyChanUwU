#include "screens.h"
#include "game.h"
#include <raylib.h>

void updateScreens(Player& player, Player& player2,Obstacle& obstacle, Obstacle& obstacle2, GameScreen& actualScreen, ParallaxBackground& backGround)
{
	if (actualScreen == MENU)
	{
		if (IsKeyPressed(KEY_ONE))
		{
			startGame(player,player2 , obstacle, obstacle2, backGround);
			actualScreen = PLAY;
		}
		if (IsKeyPressed(KEY_TWO))
		{
			actualScreen = CREDITS;
		}
		if (IsKeyPressed(KEY_THREE))
		{
			actualScreen = OPTIONS;
		}
		if (IsKeyPressed(KEY_FOUR))
		{
			actualScreen = TUTORIAL;
		}
		if (IsKeyPressed(KEY_FIVE))
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
			startGame(player,player2 ,obstacle, obstacle2, backGround);
		}
	}
	else if (actualScreen == OPTIONS)
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			actualScreen = MENU;
		}

		if ((IsKeyPressed(KEY_J)) && !player2.isActive)
		{
			player2.isActive = true;
		}
		else if ((IsKeyPressed(KEY_J)) && player2.isActive)
		{
			player2.isActive = false;
		}
	}
	//actualizacion
	else if (actualScreen == PLAY)
	{
		if (player2.isActive)
		{
			player2Movement(player2);
		}
		player1Movement(player);
		obstacleMovement(obstacle, obstacle2, screenWidth, screenHeight);
		loseConditions(obstacle, obstacle2, player, actualScreen);
		if (player2.isActive)
		{
			loseConditions(obstacle, obstacle2, player2, actualScreen);
		}
		updateParallax(backGround);

		if (IsKeyPressed(KEY_ESCAPE))
		{
			actualScreen = MENU;
		}
	}
}
void drawScreens(Player player1, Player player2,Obstacle obstacle, Obstacle obstacle2, GameScreen actualScreen, ParallaxBackground& backGround)
{

	if (actualScreen == MENU)
	{
		DrawText("FlappuChanUwU", screenWidth / 8, static_cast <int>(screenHeight * 0.2), 50, WHITE);
		DrawText("1. JUGAR", screenWidth / 8, static_cast <int>(screenHeight * 0.5), 40, GREEN);
		DrawText("2. CREDITOS", screenWidth / 8, static_cast <int>(screenHeight * 0.6), 40, YELLOW);
		DrawText("3. OPTIONS", screenWidth / 8, static_cast <int>(screenHeight * 0.7), 40, PINK);
		DrawText("4. TUTORIAL", screenWidth / 8, static_cast <int>(screenHeight * 0.8), 40, BLUE);
		DrawText("5. SALIR", screenWidth / 8, static_cast <int>(screenHeight * 0.9), 40, RED);
	}
	else if (actualScreen == PLAY)
	{
		drawParallax(backGround);
		//jugador
		DrawRectangle(static_cast<int>(player1.positionX), static_cast<int>(player1.positionY), static_cast<int>(player1.rectangleSize), static_cast<int>(player1.rectangleSize), PURPLE);
		if (player2.isActive)
		{
			DrawRectangle(static_cast<int>(player2.positionX), static_cast<int>(player2.positionY), static_cast<int>(player2.rectangleSize), static_cast<int>(player2.rectangleSize), PINK);
		}
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
	else if (actualScreen == OPTIONS)
	{
		if (!player2.isActive)
		{
			DrawText("J para cambiar a 2 jugadores", screenWidth / 8, static_cast <int>(screenHeight * 0.4), 40, WHITE);
		}
		else if (player2.isActive)
		{
			DrawText("J para cambiar a 1 jugador", screenWidth / 8, static_cast <int>(screenHeight * 0.4), 40, WHITE);
		}

		DrawText("ESCAPE para volver al menu", screenWidth / 8, static_cast <int>(screenHeight * 0.5), 40, WHITE);
	}
	else if (actualScreen == LOSE)
	{
		DrawText("puntaje", screenWidth / 8, static_cast <int>(screenHeight * 0.3), 50, WHITE);
		DrawText("R para reintentar", screenWidth / 8, static_cast <int>(screenHeight *  0.4), 40, WHITE);
		DrawText("ESCAPE para volver al menu", screenWidth / 8, static_cast <int>(screenHeight * 0.5), 40, WHITE);
	}
}