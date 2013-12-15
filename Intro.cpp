#pragma once
#include "Intro.h"

// Represents the intro
void Intro::show(sf::RenderWindow &window)
{
	// Loads
	sf::Texture texture;
	if(texture.loadFromFile("images/Intro.png") != true) {
		return;
	}

	sf::Sprite sprite(texture);
	window.draw(sprite);
	window.display();

	sf::Event currentEvent;
	while(true)
	{
		while(window.pollEvent(currentEvent))
		{
			// Close the screen if close is clicked
			if(currentEvent.type == sf::Event::Closed) { 
				exit(0);
			}

			if(currentEvent.type == sf::Event::EventType::KeyPressed 
				|| currentEvent.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}