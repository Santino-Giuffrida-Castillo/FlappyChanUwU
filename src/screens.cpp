#include "screens.h"

#include "raylib.h"

#include "game.h"


namespace flappyBird
{

	void updateScreens(Player& player, Player& player2, Obstacle& obstacle, Obstacle& obstacle2, GameScreen& actualScreen, ParallaxBackground& backGround)
	{
		if (actualScreen == MENU)
		{
			if (IsKeyPressed(KEY_ONE))
			{
				playClickSound();
				playInGameMusic();
				startGame(player, player2, obstacle, obstacle2);
				actualScreen = PLAY;
			}
			if (IsKeyPressed(KEY_TWO))
			{
				playClickSound();
				actualScreen = CREDITS;
			}
			if (IsKeyPressed(KEY_THREE))
			{
				playClickSound();
				actualScreen = OPTIONS;
			}
			if (IsKeyPressed(KEY_FOUR))
			{
				playClickSound();
				actualScreen = TUTORIAL;
			}
			if (IsKeyPressed(KEY_FIVE))
			{
				playClickSound();
				actualScreen = EXIT;
			}

		}
		else if (actualScreen == CREDITS)
		{

			if (IsKeyPressed(KEY_ESCAPE))
			{
				playClickSound();
				actualScreen = MENU;
			}

		}
		else if (actualScreen == TUTORIAL)
		{

			if (IsKeyPressed(KEY_ESCAPE))
			{
				playClickSound();
				actualScreen = MENU;
			}

		}
		else if (actualScreen == LOSE)
		{

			if (IsKeyPressed(KEY_ESCAPE))
			{
				playClickSound();
				actualScreen = MENU;

			}
			if (IsKeyPressed(KEY_R))
			{
				playClickSound();
				playInGameMusic();
				actualScreen = PLAY;
				startGame(player, player2, obstacle, obstacle2);

			}

		}
		else if (actualScreen == OPTIONS)
		{

			if (IsKeyPressed(KEY_ESCAPE))
			{
				playClickSound();
				actualScreen = MENU;
			}

			if ((IsKeyPressed(KEY_J)) && !player2.isActive)
			{
				playClickSound();
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

			addPoints(obstacle, player, player2);

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
				playClickSound();
				playMenuMusic();
				actualScreen = MENU;
			}

		}
	}

	void drawScreens(Player player1, Player player2, Obstacle obstacle, Obstacle obstacle2, GameScreen actualScreen, ParallaxBackground& backGround)
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
			DrawText("V1.0", 0, 0, 20, WHITE);
			DrawText(TextFormat("P1 Puntos: %i", player1.points), 20, 20, 30, WHITE);

	
			if (player2.isActive)
			{
				DrawText(TextFormat("P2 Puntos: %i", player2.points), screenWidth - 260, 20, 30, PINK);
			}

			//jugador
			DrawTexturePro(player1.texture, player1.source, player1.dest, player1.origin, 0.0f, WHITE);
			if (player2.isActive)
			{
				DrawTexturePro(player2.texture, player2.source, player2.dest, player2.origin, 0.0f, RED);
			}
			//obstáculo superior
			DrawRectangle(static_cast<int>(obstacle.positionX), static_cast<int>(obstacle.positionY), static_cast<int>(obstacle.sizeX), static_cast<int>(obstacle.sizeY), WHITE);

			//obstáculo inferior
			DrawRectangle(static_cast<int>(obstacle2.positionX), static_cast<int>(obstacle2.positionY), static_cast<int>(obstacle2.sizeX), static_cast<int>(obstacle2.sizeY), WHITE);


		}
		else if (actualScreen == CREDITS)
		{

			DrawText("DESARROLLADOR/ES", screenWidth / 8, static_cast <int>(screenHeight * 0.4), 40, WHITE);
			DrawText("Desarrollador anterior:Manaos_ChanUwU", screenWidth / 8, static_cast <int>(screenHeight * 0.5), 30, VIOLET);
			DrawText("Desarrollador actual:Santino Giuffrida Castillo", screenWidth / 8, static_cast <int>(screenHeight * 0.6), 30, VIOLET);
			DrawText("ESCAPE para volver al menu", screenWidth / 8, static_cast <int>(screenHeight * 0.75), 40, WHITE);

		}
		else if (actualScreen == TUTORIAL)
		{

			DrawText("JUGADOR1:W para saltar", screenWidth / 8, static_cast <int>(screenHeight * 0.4), 40, WHITE);
			DrawText("JUGADOR2(Rojo):ESPACIO para saltar", screenWidth / 8, static_cast <int>(screenHeight * 0.45), 40, WHITE);
			DrawText("ESCAPE para volver al menu", screenWidth / 8, static_cast <int>(screenHeight * 0.5), 40, WHITE);

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
			int baseX = screenWidth / 8;

			DrawText(TextFormat("Puntaje P1: %i", player1.points), baseX, static_cast<int>(screenHeight * 0.25f), 45, WHITE);
			if (player2.isActive)
			{
				DrawText(TextFormat("Puntaje P2: %i", player2.points), baseX, static_cast<int>(screenHeight * 0.35f), 45, PINK);
			}
			DrawText("R para reintentar", screenWidth / 8, static_cast <int>(screenHeight * 0.4), 40, WHITE);
			DrawText("ESCAPE para volver al menu", screenWidth / 8, static_cast <int>(screenHeight * 0.5), 40, WHITE);

		}
	}
}