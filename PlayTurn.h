#pragma once
#include "Header.h"

// Forward declerations
class Trainer;

class Pokemon;
class Fire;
class Grass;
class Water;
class Item;

// Plays a whole turn in a battle. Both the
// user and the computer
class PlayTurn {

public:
	// Plays the whole turn
	static BattleState PlayTurnWhole(Trainer * user, Trainer * ash, Action action);

	// Plays the user
	static BattleState PlayTurnUser(Trainer * user, Trainer * ash, Action action);

	// Plays Ash
	static BattleState PlayTurnAsh(Trainer * user, Trainer * ash);

	// Check if the Pokemon are all fainted
	static bool CheckIfAllFainted(Trainer * opponentPlayer);

	// Check if a new Pokemon needs to be switched into
	// battle, aka the one out has fainted
	static void CheckIfNeedSwitch(Trainer * trainer);

};