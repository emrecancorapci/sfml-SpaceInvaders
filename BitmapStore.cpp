#include "BitmapStore.h"
#include <cassert>

BitmapStore* BitmapStore::sharedInstance = nullptr;

BitmapStore::BitmapStore()
{
	assert(sharedInstance == nullptr);
	sharedInstance = this;
}

void BitmapStore::addBitmap(string const& filename)
{
	// Get a reference
	auto& bitmapMap = sharedInstance->_bitmapsMap;

	// Kvp iterator - find file
	const auto keyValuePair = bitmapMap.find(filename);

	const bool thereIsNoMatch = keyValuePair == bitmapMap.end();

	if (thereIsNoMatch)
	{
		auto& texture = bitmapMap[filename];
		texture.loadFromFile(filename);
	}
}

Texture& BitmapStore::getBitmap(std::string const& filename)
{
	// Get a reference
	auto& reference = sharedInstance->_bitmapsMap;

	const auto keyValuePair = reference.find(filename);

	const bool thereIsAMatch = keyValuePair != reference.end();

	if(thereIsAMatch)
	{
		return keyValuePair->second;
	}
	else
	{
#ifdef debuggingOnConsole
		cout << filename << " texture not found." << endl;

#endif
		return keyValuePair->second;
	}
}


