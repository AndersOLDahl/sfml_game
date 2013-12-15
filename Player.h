#pragma once
#include "Header.h"
#include "DisplayedObject.h"
#include <vector>

// Represents a player
class Player : public DisplayedObject {

public:
	Player();
	~Player();

	// Moves the player
	void Move(Direction direction);

	// Draws the player to screen
	void Draw(sf::RenderWindow &window);

	friend class Game;

private:
	sf::IntRect m_intRect;

};
