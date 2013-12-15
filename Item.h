#pragma once
#include "Header.h"

class Pokemon;

// Represents an item
class Item {

public:
	std::string m_name;

	// Heal amount
	int m_restoreAmount;

	Item();
	Item(std::string name, int restoreAmount);
	virtual ~Item();

	void heal(Pokemon * pokemon);

};