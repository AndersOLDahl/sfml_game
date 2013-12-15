#pragma once
#include "Header.h"

// Represents an object that is displayed to
// screen
class DisplayedObject {

public:

	// X and Y location of the object
	float m_x;
	float m_y;

	DisplayedObject();
	virtual ~DisplayedObject();

	// Loads the object from a file
	virtual void Load(std::string filename);

	// Draws the object
	virtual void Draw(sf::RenderWindow &window);

	// Sets a new position of the object
	virtual void SetPosition(float x, float y);

protected:
	bool m_loaded;
	sf::Sprite m_sprite;

private:
	sf::Texture m_texture;
	std::string m_filename;
	
};
