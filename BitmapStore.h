#pragma once
#ifndef BITMAP_STORE_H
#define BITMAP_SHORE_H

#include <SFML/Graphics.hpp>
#include <map>


using namespace sf;
using namespace std;

class BitmapStore
{
private:
	map<std::string, Texture> _bitmapsMap;
	static BitmapStore* sharedInstance;

public:
	BitmapStore();
	static Texture& getBitmap(string const& filename);
	static void addBitmap(string const& filename);
	static bool thereIsMatch(string const& filename);
};

#endif
