

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 




#include "Game.h"
#include <time.h>






int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();
}


Game::Game() : window(sf::VideoMode(static_cast<int>(scrWidth), static_cast<int>(scrHeight)), "lab4 animating sprite", sf::Style::Default)
// Default constructor
{

	flowerStartFrame = flowerGrowinStartFrame;
	flowerEndFrame = flowerGrowingEndFrame;
	flowerAnimationframe = flowerGrowinStartFrame;
	flowerAnimationTime = 400;
	scrollingbackground.Init(window);

}



void Game::loadContent()
{

}





void Game::run()
{

	srand((int)time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop


}



int Game::NextAnimationFrame(int& elapsed, int animationFrame, int animationTime, int startFrame, int endFrame)
{
	elapsed++;
	if (elapsed > animationTime)
	{
		elapsed = 0;
		animationFrame++;
		if (animationFrame > endFrame)
		{
			animationFrame = startFrame;
		}
	}
	return animationFrame;
}


void Game::update()
{
	//updating the animation frame

	// get keyboard input for PLAYER 
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

	}

	sf::Vector2i localPosition = sf::Mouse::getPosition(window);

}


void Game::draw()
{
	window.clear();
	
	scrollingbackground.Draw(window);
	scrollingbackground.Update(window);
	window.display();
}

sf::IntRect Game::GetFrameRectangle(int frameNum, int frameWidth, int frameHeigth, int numColums)
{
	return sf::IntRect();
}
