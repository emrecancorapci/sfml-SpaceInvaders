#include "SoundEngine.h"
#include <SFML/Audio.hpp>
#include <cassert>

SoundEngine* SoundEngine::sharedInstance = nullptr;

void CreateSound(SoundObject& soundObject, const string& file) 
{
	soundObject.buffer.loadFromFile(file);
	soundObject.sound.setBuffer(soundObject.buffer);
}

SoundEngine::SoundEngine()
{
	assert(sharedInstance == nullptr);
	sharedInstance = this;


	CreateSound(_shoot, "sound/shoot.ogg");
	CreateSound(_playerExplode, "sound/playerexplode.ogg");
	CreateSound(_invaderExplode, "sound/invaderexplode.ogg");
	CreateSound(_click, "sound/click.ogg");

	/*
	_shoot.buffer.loadFromFile("sound/shoot.ogg");
	_playerExplode.buffer.loadFromFile("sound/playerexplode.ogg");
	_invaderExplode.buffer.loadFromFile("sound/invaderexplode.ogg");
	_click.buffer.loadFromFile("sound/click.ogg");

	_shoot.sound.setBuffer(_shoot.buffer);
	_playerExplode.sound.setBuffer(_playerExplode.buffer);
	_invaderExplode.sound.setBuffer(_invaderExplode.buffer);
	_click.sound.setBuffer(_click.buffer);
	*/
}

void SoundEngine::playShoot()
{
	sharedInstance->_shoot.sound.play();
}

void SoundEngine::playPlayerExplode()
{
	sharedInstance->_playerExplode.sound.play();
}

void SoundEngine::playInvaderExplode()
{
	sharedInstance->_invaderExplode.sound.play();
}

void SoundEngine::playClick()
{
	sharedInstance->_click.sound.play();
}



