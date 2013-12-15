#include "Item.h"
#include "Pokemon.h"

// Represents an item
Item::Item () {

}

Item::Item(std::string name, int restoreAmount) {

	m_name = name;
	m_restoreAmount = restoreAmount;

}

Item::~Item() {

}

// Heals the Pokemon using a potion or a superpotion
void Item::heal(Pokemon * pokemon) {

	if(m_name == "SuperPotion") {
		pokemon -> m_health += 50;

		if(pokemon -> m_health >= 100) {
			pokemon -> m_health = 100;
		}

		assert(pokemon -> m_health <= 100 &&
			pokemon -> m_health >= 0);

	} else {
		pokemon -> m_health += 20;

		if(pokemon -> m_health >= 100) {
			pokemon -> m_health = 100;
		}

		assert(pokemon -> m_health <= 100 &&
			pokemon -> m_health >= 0);
	}

}