#pragma once

#include <raylib.h>

namespace flappyBird
{

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
		Texture2D texture;
		Sound deadSound;
		Sound jumpSound;
		

	};

	void player1Movement(Player& player);
	void player2Movement(Player& player);
	void assignPlayerAssets(Player& player);
	void loadPlayerAssets();
	void unloadPlayerAssets();


}