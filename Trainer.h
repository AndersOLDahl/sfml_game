#pragma once
#include "Header.h"
#include "Pokemon.h"
#include "Item.h"

// Forward declerations
class Pokemon;
class Item;

// Represents a trainer
class Trainer {

public:
	bool m_computer;
	int m_wins;
	int m_currentPokemon;
	bool m_allFainted;
	std::string m_name;
	std::vector<Pokemon*> m_pokemon;
	std::vector<Item*> m_item;

	Trainer();
	Trainer(std::string name);
	~Trainer();

	// Draw a trainer
	void Draw(sf::RenderWindow &window);

	// Checks if all Pokemon are fainted
	bool AllFainted();

	// Display the health of all Pokemon
	void DisplayHealth();

private:
	// User's Pokemon and Items
	static Fire uF1;
	static Fire uF2;
	static Water uW3;
	static Water uW4;
	static Grass uG5;
	static Grass uG6;
	static Item uI1;
	static Item uI2;

	// Ash's Pokemon
	static Fire aF1;
	static Fire aF2;
	static Water aW3;
	static Water aW4;
	static Grass aG5;
	static Grass aG6;

};