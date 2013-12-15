#pragma once
#include "Player.h"

Player::Player() : 
	m_intRect(sf::IntRect(64, 0, 32, 32))
{
}

Player::~Player()
{
}

// Draws the player to screen if it is loaded
void Player::Draw(sf::RenderWindow &window)
{
	if(m_loaded) {

		m_sprite.setTextureRect(m_intRect);
		window.draw(m_sprite);

	}
}

// Moves the player - up, down, left, or right
void Player::Move(Direction direction) {

	if(direction == UP) {

		this -> m_y = m_y - 5;
		this -> SetPosition(m_x, m_y);

		if(this -> m_y < 30) {
			this -> m_y = 30;
		}

	} else if (direction == DOWN) {

		this -> m_y = m_y + 5;
		this -> SetPosition(m_x, m_y);

		if(this -> m_y > SCREENHEIGHT - 30) {
			this -> m_y = SCREENHEIGHT - 30;
		}

	} else if (direction == LEFT) {

		this -> m_x = m_x - 5;
		this -> SetPosition(m_x, m_y);

		if(this -> m_x < 30) {
			this -> m_x = 30;
		}

	} else if (direction == RIGHT) {

		this -> m_x = m_x + 5;
		this -> SetPosition(m_x, m_y);

		if(this -> m_x > SCREENWIDTH - 30) {
			this -> m_x = SCREENWIDTH - 30;
		}		

	}

}
