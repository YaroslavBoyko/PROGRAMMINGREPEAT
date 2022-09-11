#pragma once
#pragma once
#include "SFML/Graphics.hpp"

class BackGroundTile
{
public:
	sf::Sprite TileSprite;
	sf::Texture TileTexture;

private:

};

class ScrollingBackGround
{
public:
	static const int numTiles = 3;
	BackGroundTile tiles[numTiles];

	void Init(sf::RenderWindow& win);

	void Update(sf::RenderWindow& win);

	void Draw(sf::RenderWindow& win);
};