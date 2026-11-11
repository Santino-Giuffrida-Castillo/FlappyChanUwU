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
	bool isActive;

};
void player1Movement(Player& player);
void player2Movement(Player& player);