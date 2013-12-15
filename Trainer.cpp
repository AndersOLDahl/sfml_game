#include "Trainer.h"
#include <iostream>

Trainer::Trainer() :
	m_wins(0), 
	m_currentPokemon(0),
	m_name("Anders"),
	m_computer(false),
	m_allFainted(false)
{
}

Trainer::Trainer(std::string name) :
	m_wins(0),
	m_currentPokemon(0),
	m_name(name), 
	m_computer(true),
	m_allFainted(false)
{
}

Trainer::~Trainer()
{
}

// Draws the trainer to the scene
void Trainer::Draw(sf::RenderWindow &window) {

	m_pokemon.at(m_currentPokemon) -> Draw(window);

}

// Check if all the trainer's Pokemon are fainted
bool Trainer::AllFainted() {

	assert (m_pokemon.size() == 6);

	for (unsigned int i = 0; i < m_pokemon.size(); i++) {
		if(!m_pokemon.at(i) -> m_isFainted) {

			return false;

		}
	}

	return true;

}

// Display the health of all Pokemon on the CMD
void Trainer::DisplayHealth() {

	assert (m_pokemon.size() == 6);

	std::cout << m_name << ": " << std::endl << std::endl;
	for (unsigned int i = 0; i < m_pokemon.size(); i++) {
		m_pokemon.at(i) -> displayHealth();
	}
	std::cout << std::endl;

}