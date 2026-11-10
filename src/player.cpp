#include "player.h"
#include <raylib.h>


void playerMovement(Player& player, const int screenHeight)
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