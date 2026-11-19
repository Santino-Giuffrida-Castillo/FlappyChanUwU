#include "gameAudio.h"
namespace flappyBird
{
	static Sound initSound;
	static Sound clickSound;
	static Sound pointSound;
	static Music menuMusic;
	static Music inGameMusic;

	void loadGameAudio()
	{
		initSound = LoadSound("res/init.wav");
		clickSound = LoadSound("res/click.wav");
		pointSound = LoadSound("res/point.wav");
		menuMusic = LoadMusicStream("res/musicMenu.wav");
		inGameMusic = LoadMusicStream("res/musicInGame.wav");
		SetSoundVolume(initSound, 0.3f);
		SetSoundVolume(clickSound, 0.3f);
		SetSoundVolume(pointSound, 0.3f);

		SetMusicVolume(menuMusic, 0.3f); 
		SetMusicVolume(inGameMusic, 0.3f);
	}

	void unloadGameAudio()
	{
		UnloadSound(initSound);
		UnloadSound(clickSound);
		UnloadSound(pointSound);
		UnloadMusicStream(menuMusic);
		UnloadMusicStream(inGameMusic);
	}

	void playInitSound()
	{
		PlaySound(initSound);
	}

	void playClickSound()
	{
		PlaySound(clickSound);
	}

	void playPointSound()
	{
		PlaySound(pointSound);
	}

	void playMenuMusic()
	{
		StopMusicStream(inGameMusic);
		PlayMusicStream(menuMusic);
	}

	void playInGameMusic()
	{
		StopMusicStream(menuMusic);
		PlayMusicStream(inGameMusic);
	}

	void updateGameMusic(bool isPlaying)
	{
		if (isPlaying)
		{
			UpdateMusicStream(inGameMusic);
		}
		else
		{
			UpdateMusicStream(menuMusic);
		}
	}
}