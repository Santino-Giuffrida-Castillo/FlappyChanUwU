#include "player.h"
#include <raylib.h>

namespace flappyBird
{

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

}