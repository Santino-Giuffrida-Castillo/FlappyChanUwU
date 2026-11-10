#pragma once
struct Player
{
	float positionX;
	float positionY;
	int points;
	float rectangleSize;
	float speedY;
	float flappForce;
	float gravity;
};
void playerMovement(Player& player, const int screenHeight);