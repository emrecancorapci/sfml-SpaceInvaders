#pragma once
#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H

#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

struct SoundObject
{
	SoundBuffer buffer;
	Sound sound;
};

class SoundEngine
{
private:
	SoundObject _shoot;
	SoundObject _playerExplode;
	SoundObject _invaderExplode;
	SoundObject _click;

	SoundBuffer _shootBuffer;
	SoundBuffer _playerExplodeBuffer;
	SoundBuffer _invaderExplodeBuffer;
	SoundBuffer _clickBuffer;

	Sound _shootSound;
	Sound _playerExplodeSound;
	Sound _invaderExplodeSound;
	Sound _uSound;
	Sound _oSound;
	Sound _clickSound;

public:
	SoundEngine();

	void CreateSound(SoundObject& soundObject, string file);

	static void playShoot();
	static void playPlayerExplode();
	static void playInvaderExplode();
	static void playClick();

	static SoundEngine* sharedInstance;

};

#endif

