#include "Pokemon.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// The weather is the same for all pokemon.
	// RAINYDAY gives water types a 50% special attack increase
	// SUNNYDAY gives fire types a 50% special attack increase
	// SANDSTORM gives grass types a 50% special attack increase
Weather Pokemon::weather;

// Constructor for Pokemon without a name
Pokemon::Pokemon(Type type) :
	m_health (100),
	m_type (type),
	m_isFainted (false) {

	if(type == WATER) {
		m_name = "Squirtle";
	} else if (type == GRASS) {
		m_name = "Bulbasaur";
	} else if (type == FIRE) {
		m_name = "Charmander";
	}
}

// Constructor for Pokemon with a name
Pokemon::Pokemon(Type type, std::string name) :
	m_health (100),
	m_type(type),
	m_name(name),
	m_isFainted (false) {

}

Pokemon::~Pokemon() {

}

// Normal attack deals 20 damage
void Pokemon::attackNormal (Pokemon * opponentPokemon) {

	opponentPokemon -> m_health = opponentPokemon -> m_health - 20;
	opponentPokemon -> changeIfFainted();

	assert(opponentPokemon -> m_health <= 100 &&
		opponentPokemon -> m_health >= 0);

}

// Heal heals 20 health
void Pokemon::heal() {

	m_health += 20;

	if ( m_health > 100 ) {

		m_health = 100;

	}

	assert(m_health <= 100 && m_health >= 0);
}

// Checks if this Pokemon is fainted
void Pokemon::changeIfFainted() {

	if(this -> m_health <= 0) {

		m_health = 0;
		m_isFainted = true;

	}

	assert(m_health <= 100 && m_health >= 0);

}

// Plays a random move. The computer player uses this.
void Pokemon::playRandom(Pokemon * opponentPokemon) {

	srand(time(NULL));
	int randomAttack = (rand() % 4) + 1;

	assert(randomAttack <= 4 && randomAttack >= 1);
	
	if(randomAttack == 1)
		this -> attackNormal(opponentPokemon);
	if(randomAttack == 2)
		this -> specialAttack(opponentPokemon);
	if(randomAttack == 3)
		this -> heal();
	if(randomAttack == 4)
		this -> changeWeather();
}

// Displays the health of the Pokemon in the CMD
void Pokemon::displayHealth() {

	std::cout << m_name << " " << m_health << std::endl;

}

// Fire type
Fire::Fire() 
	: Pokemon(FIRE)
{

}

Fire::Fire(std::string name) 
	: Pokemon(FIRE, name)
{

}

Fire::~Fire () {

}

// The special attack deals 50% more if the type of the Pokemon
// matches the weather and 300% more if the opponent's Pokemon is weak
// to the Pokemon's type
void Fire::specialAttack(Pokemon * opponentPokemon) {

	int damage = 10;

	if (weather == SUNNYDAY) {

		damage =  int(damage * 1.50);

	}

	if (opponentPokemon -> m_type == GRASS) {

		damage = (int (damage * 3.0));

	}

	assert(damage <= 45 && damage >= 10);

	opponentPokemon -> m_health = opponentPokemon -> m_health - damage;
	opponentPokemon -> changeIfFainted();

}

// Changes the weather
void Fire::changeWeather() {

	weather = SUNNYDAY;

}

// Water type
Water::Water() 
	: Pokemon(WATER)
{

}

Water::Water(std::string name) 
	: Pokemon(WATER, name)
{

}

Water::~Water () {

}

// The special attack deals 50% more if the type of the Pokemon
// matches the weather and 300% more if the opponent's Pokemon is weak
// to the Pokemon's type
void Water::specialAttack(Pokemon * opponentPokemon) {

	int damage = 10;

	if (weather == RAINDANCE) {

		damage =  int(damage * 1.50);

	}

	if (opponentPokemon -> m_type == FIRE) {

		damage = (int (damage * 3.0));

	}

	assert(damage <= 45 && damage >= 10);

	opponentPokemon -> m_health = opponentPokemon -> m_health - damage;
	opponentPokemon -> changeIfFainted();

}

// Changes the weather
void Water::changeWeather() {

	weather = RAINDANCE;

}

// Grass type
Grass::Grass() 
	: Pokemon(GRASS)
{

}

Grass::Grass(std::string name) 
	: Pokemon(GRASS, name)
{

}

Grass::~Grass () {

}

// The special attack deals 50% more if the type of the Pokemon
// matches the weather and 300% more if the opponent's Pokemon is weak
// to the Pokemon's type
void Grass::specialAttack(Pokemon * opponentPokemon) {

	int damage = 10;

	if (weather == SANDSTORM) {

		damage =  int(damage * 1.50);

	}

	if (opponentPokemon -> m_type == WATER) {

		damage = int(damage * 3.0);

	}

	assert(damage <= 45 && damage >= 10);

	opponentPokemon -> m_health = opponentPokemon -> m_health - damage;
	opponentPokemon -> changeIfFainted();

}

// Changes the weather
void Grass::changeWeather() {

	weather = SANDSTORM;

}