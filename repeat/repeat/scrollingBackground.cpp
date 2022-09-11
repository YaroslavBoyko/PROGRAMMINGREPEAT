#include "ScrollingBackground.h"


void ScrollingBackGround::Init(sf::RenderWindow& win)
{
	tiles[0].TileTexture.loadFromFile("backgroundDino.png");
	tiles[0].TileSprite.setTexture(tiles[0].TileTexture);

	tiles[1].TileTexture.loadFromFile("backgroundDino.png");
	tiles[1].TileSprite.setTexture(tiles[1].TileTexture);

	tiles[2].TileTexture.loadFromFile("backgroundDino.png");
	tiles[2].TileSprite.setTexture(tiles[2].TileTexture);

	int xPosition = 0;
	for (int i = 0; i < numTiles; i++)
	{
		tiles[i].TileSprite.setPosition(xPosition, 0);
		xPosition += tiles[i].TileSprite.getGlobalBounds().width;
	}
}

void ScrollingBackGround::Update(sf::RenderWindow& win)
{
	for (int i = 0; i < numTiles; i++)
	{
		tiles[i].TileSprite.move(-2, 0);

		if (tiles[i].TileSprite.getPosition().x <= -tiles[0].TileSprite.getGlobalBounds().width)
		{
			tiles[i].TileSprite.setPosition(sf::Vector2f(tiles[0].TileSprite.getGlobalBounds().width * (numTiles - 1), 0));
		}
	}


}


void ScrollingBackGround::Draw(sf::RenderWindow& win)
{
	for (int i = 0; i < numTiles; i++)
	{
		win.draw(tiles[i].TileSprite);
	}
}