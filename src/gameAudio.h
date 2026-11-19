#pragma once
#include <raylib.h>
namespace flappyBird
{
	void loadGameAudio();
	void unloadGameAudio();


	void playInitSound();
	void playClickSound();
	void playPointSound();


	void playMenuMusic();
	void playInGameMusic();
	void updateGameMusic(bool isPlaying);
}