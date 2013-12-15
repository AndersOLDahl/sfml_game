#pragma once
#include "Header.h"
#include "DisplayedObject.h"

// Represents a Pokemon
class Pokemon : public DisplayedObject {

public:
	int m_health;
	Type m_type;
	std::string m_name;
	bool m_isFainted;
	
	// Weather for all Pokemon
	static Weather weather;

	Pokemon(Type type);
	Pokemon(Type type, std::string name);
	virtual ~Pokemon();

	// Deals 20 damage
	void attackNormal(Pokemon * opponentPokemon);

	// Heals 20 damage
	void heal();

	// Special attack, damage depends on the opponent
	// type and weather
	virtual void specialAttack(Pokemon * opponentPokemon) = 0;

	// Changes the weather to that of the Pokemon's type
	virtual void changeWeather() = 0;

	// Checks if the Pokemon fainted
	void changeIfFainted();

	// Play random attack
	void playRandom(Pokemon * opponentPokemon);

	// Display the health of the Pokemon
	void displayHealth();

};

// Represents a Fire type Pokemon
class Fire : public Pokemon {

public:
	Fire();
	Fire(std::string name);
	virtual ~Fire();

	void specialAttack(Pokemon * opponentPokemon);
	void changeWeather();

};

// Represents a Water type Pokemon
class Water : public Pokemon {

public:
	Water();
	Water(std::string name);
	virtual ~Water();

	void specialAttack(Pokemon * opponentPokemon);
	void changeWeather();

};

// Represents a Grass type Pokemon
class Grass : public Pokemon {

public:
	Grass();
	Grass(std::string name);
	virtual ~Grass();

	void specialAttack(Pokemon * opponentPokemon);
	void changeWeather();

};
