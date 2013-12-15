#pragma once
#include "Header.h"
#include "Game.h"

// Forward declare Trainer and PlayTurn
class Trainer;
class PlayTurn;

// Represents a battle in the game
class Battle {

public:
	// Shows the battle
	void show(sf::RenderWindow &window);

private:
	// Represents the state of the game
		// Lose, Won, Play
	static BattleState stateOfGame;

	// Trainers
	static Trainer user;
	static Trainer ash;

	// User's pokemon
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

	// The weathers
	static DisplayedObject rain;
	static DisplayedObject sun;
	static DisplayedObject sand;

	// Health bars
	static sf::RectangleShape uH;
	static sf::RectangleShape aH;

	// Displays the health in the CMD
	static void DisplayAllHealth();

	// Draws everything to screen
	static void DrawAll(sf::RenderWindow &window, sf::Sprite * background);

	// Draws the weather to screen
	static void DrawWeather(sf::RenderWindow &window);

	// Initalizes images, user, and ash
	static void InitalizeLoads();
	static void InitalizeUser();
	static void ResetAsh();

	// Show move screen
	static void ShowMove(sf::RenderWindow &window, sf::Sprite * background);
	static BattleState chooseMove(sf::RenderWindow &window);

	// Show switch screen
	static void ShowPokemon(sf::RenderWindow &window, sf::Sprite * background);
	static BattleState choosePokemon(sf::RenderWindow &window);

	// Show item screen
	static void ShowItem(sf::RenderWindow &window, sf::Sprite * background);
	static BattleState choosePotion(sf::RenderWindow &window);

};

