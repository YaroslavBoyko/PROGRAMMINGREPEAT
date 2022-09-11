#pragma once
#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "ScrollingBackground.h"
#include "player.h"

const float scrHeight = 800;
const float scrWidth = 1000;

class Game
{
	sf::RenderWindow window;

	ScrollingBackGround scrollingbackground;

private:


public:

	Game();

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	void loadContent();
	void update();
	void run();
	void draw();
	sf::IntRect GetFrameRectangle(int frameNum, int frameWidth, int frameHeigth, int numColums);
	sf::IntRect rectResourceSprite;
	sf::Clock clock;

	int flowerStartFrame;
	int flowerGrowinStartFrame;
	int flowerEndFrame;
	int flowerGrowingEndFrame;
	int flowerAnimationframe;
	int flowerAnimationTime;
	int flowerTotalElapsed;

	int NextAnimationFrame(int& elapsed, int animationFrame, int animationTime, int startFrame, int endFrame);

};