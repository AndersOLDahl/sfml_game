#pragma once
#include "DisplayedObject.h"

DisplayedObject::DisplayedObject()
	: m_loaded(true)
{

}


DisplayedObject::~DisplayedObject()
{
}

// Loads the displayed object if
// a valid filename is provided
void DisplayedObject::Load(std::string filename)
{
	if(m_texture.loadFromFile(filename) == false)
	{
		m_loaded = false;
	}
	else
	{
		m_sprite.setTexture(m_texture);
		m_filename = filename;
		m_loaded = true;
	}
}

// Draw the displayed objects
void DisplayedObject::Draw(sf::RenderWindow &window)
{
	if(m_loaded)
	{
		window.draw(m_sprite);
	}
}

// Set the position of the displayed object
void DisplayedObject::SetPosition(float x, float y)
{
	if(m_loaded)
	{
		m_x = x;
		m_y = y;
		m_sprite.setPosition(x ,y);
	}
}