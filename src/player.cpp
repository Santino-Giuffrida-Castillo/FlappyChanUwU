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
			PlaySound(player.jumpSound);
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
		player.origin = { player.rectangleSize / 2.0f, player.rectangleSize / 2.0f };
		player.dest = {
			player.positionX + player.origin.x,
			player.positionY + player.origin.y,
			player.rectangleSize,
			player.rectangleSize
		};

	}
	void player2Movement(Player& player)
	{

		if (IsKeyPressed(KEY_SPACE))
		{
			PlaySound(player.jumpSound);
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
		player.origin = { player.rectangleSize / 2.0f, player.rectangleSize / 2.0f };
		player.dest = {
			player.positionX + player.origin.x,
			player.positionY + player.origin.y,
			player.rectangleSize,
			player.rectangleSize
		};

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
		jumpSound = LoadSound("res/jump.wav");
		deadSound = LoadSound("res/death.wav");

		SetSoundVolume(jumpSound, 0.5f);
	}

	void unloadPlayerAssets()
	{
		UnloadTexture(playerTexture);
		UnloadSound(jumpSound);
		UnloadSound(deadSound);
	}

}