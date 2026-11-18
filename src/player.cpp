#include "player.h"

#include "raylib.h"

namespace flappyBird
{

	static Texture2D playerTexture;
	static Sound deadSound;
	static Sound jumpSound;

	void player1Movement(Player& player)
	{

		if (IsKeyPressed(KEY_W))
		{
			player.speedY = player.flappForce;
		}
		player.speedY += player.gravity * GetFrameTime();
		player.positionY += player.speedY * GetFrameTime();
		//techo
		if (player.positionY < 0)
		{
			player.positionY = 0;
			player.speedY = 0;
		}

	}
	void player2Movement(Player& player)
	{

		if (IsKeyPressed(KEY_SPACE))
		{
			player.speedY = player.flappForce;
		}
		player.speedY += player.gravity * GetFrameTime();
		player.positionY += player.speedY * GetFrameTime();
		//techo
		if (player.positionY < 0)
		{
			player.positionY = 0;
			player.speedY = 0;
		}

	}
	void assignPlayerAssets(Player& player)
	{
		player.texture = playerTexture;
		player.jumpSound = jumpSound;
		player.deadSound = deadSound;
	}

	void loadPlayerAssets()
	{
		playerTexture = LoadTexture("res/player.png");
		//jumpSound = LoadSound("res/shoot.wav");
		//deadSound = LoadSound("res/death.wav");
	}

	void unloadPlayerAssets()
	{
		UnloadTexture(playerTexture);
		//UnloadSound(jumpSound);
		//UnloadSound(deadSound);
	}

}