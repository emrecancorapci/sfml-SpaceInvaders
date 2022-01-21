#include "BitmapStore.h"
#include <cassert>

BitmapStore* BitmapStore::sharedInstance = nullptr;

BitmapStore::BitmapStore()
{
	assert(sharedInstance == nullptr);
	sharedInstance = this;
}

bool BitmapStore::thereIsMatch(string const& filename)
{
	auto& bitmapMap = sharedInstance->_bitmapsMap;

	// Kvp iterator - find file
	const auto keyValuePair = bitmapMap.find(filename);

	const bool match = keyValuePair != bitmapMap.end();

	return match;
}


void BitmapStore::addBitmap(string const& filename)
{
	if (!thereIsMatch(filename))
	{
		auto& texture = sharedInstance->_bitmapsMap[filename];
		texture.loadFromFile(filename);
	}
}

Texture& BitmapStore::getBitmap(std::string const& filename)
{
	const auto keyValuePair = sharedInstance->_bitmapsMap.find(filename);

	if(thereIsMatch(filename))
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


