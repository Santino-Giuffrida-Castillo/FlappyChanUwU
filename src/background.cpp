#include "background.h"
#include "screens.h"

namespace flappyBird
{

	void updateParallax(ParallaxBackground& backGround)
	{

		backGround.scrollingBack -= 40.0f * GetFrameTime();
		backGround.scrollingMid -= 120.0f * GetFrameTime();
		backGround.scrollingFore -= 250.0f * GetFrameTime();

		float scale = (float)screenHeight / backGround.back.height;

		if (backGround.scrollingBack <= -backGround.back.width * scale)
		{
			backGround.scrollingBack = 0.0f;
		}
		if (backGround.scrollingMid <= -backGround.mid.width * scale)
		{
			backGround.scrollingMid = 0.0f;
		}
		if (backGround.scrollingFore <= -backGround.front.width * scale)
		{
			backGround.scrollingFore = 0.0f;
		}

	}

	void drawParallax(ParallaxBackground& backGround)
	{

		float scale = (float)screenHeight / backGround.back.height;

		float scaledWidthBack = backGround.back.width * scale;
		float scaledWidthMid = backGround.mid.width * scale;
		float scaledWidthFore = backGround.front.width * scale;

		DrawTextureEx(backGround.back, Vector2{ backGround.scrollingBack, 0.0f }, 0.0f, scale, WHITE);
		DrawTextureEx(backGround.back, Vector2{ scaledWidthBack + backGround.scrollingBack, 0.0f }, 0.0f, scale, WHITE);


		DrawTextureEx(backGround.mid, Vector2{ backGround.scrollingMid, 0.0f }, 0.0f, scale, WHITE);
		DrawTextureEx(backGround.mid, Vector2{ scaledWidthMid + backGround.scrollingMid, 0.0f }, 0.0f, scale, WHITE);


		DrawTextureEx(backGround.front, Vector2{ backGround.scrollingFore, 0.0f }, 0.0f, scale, WHITE);
		DrawTextureEx(backGround.front, Vector2{ scaledWidthFore + backGround.scrollingFore, 0.0f }, 0.0f, scale, WHITE);

	}

	void unloadBackground(ParallaxBackground& backGround)
	{

		UnloadTexture(backGround.back);
		UnloadTexture(backGround.mid);
		UnloadTexture(backGround.front);

	}
}