#pragma once
#include "PlayTurn.h"
#include "Trainer.h"
#include "Pokemon.h"

// Checks if all Pokemon are fainted
bool PlayTurn::CheckIfAllFainted(Trainer * opponentPlayer) {

	assert(opponentPlayer -> m_pokemon.size() == 6);

	for(unsigned int i = 0; i < opponentPlayer -> m_pokemon.size(); i++) {
		if (opponentPlayer -> m_pokemon.at(i)
			-> m_isFainted == false) {
				return false;
		}
	}

	return true;
}

// Checks if the current Pokemon out needs a switch
void PlayTurn::CheckIfNeedSwitch(Trainer * trainer) {

	assert(trainer -> m_pokemon.size() == 6);

	if(trainer -> m_pokemon.at(trainer -> m_currentPokemon) -> m_isFainted == false) {

		return;

	} else {

		for(unsigned int i = 0; i < trainer -> m_pokemon.size(); i++) {

			if(trainer -> m_pokemon.at(i) -> m_isFainted == false) {

				trainer -> m_currentPokemon = i;
				return;
			}

		}

	}

}

// Plays the entire turn with both players. User and Ash.
BattleState PlayTurn::PlayTurnWhole(Trainer * user, Trainer * ash, Action action) {

	if(PlayTurnUser (user, ash, action) == WON) {
		return WON;
	}

	if(PlayTurnAsh(user, ash) == LOST) {
		return LOST;
	}

	return PLAY;

}

// Play Ash's turn
BattleState PlayTurn::PlayTurnAsh(Trainer * user, Trainer * ash) {

	ash -> m_pokemon.at(ash -> m_currentPokemon)
		-> playRandom(user -> m_pokemon.at(user
		-> m_currentPokemon));

	bool check = CheckIfAllFainted(user);

	if (check == true) {
		return LOST;
	}

	CheckIfNeedSwitch(user);

	return PLAY;

}

// Play User's turn
BattleState PlayTurn::PlayTurnUser(Trainer * user, Trainer * ash, Action action) {

	switch(action) {

	case ATTACK:
		{

			user -> m_pokemon.at(user -> m_currentPokemon) ->
				attackNormal(ash -> m_pokemon.at(ash -> m_currentPokemon));

			break;

		}

	case SPECIALATTACK:
		{

			user -> m_pokemon.at(user -> m_currentPokemon) ->
				specialAttack(ash -> m_pokemon.at(ash -> m_currentPokemon));

			break;

		}

	case HEALMOVE:
		{

			user -> m_pokemon.at(user -> m_currentPokemon) -> heal();

			break;

		}

	case CHANGEWEATHER:
		{
			user -> m_pokemon.at(user -> m_currentPokemon) -> changeWeather();

			break;
		}

	case SWITCH:
		{
			break;
		}

	case POTIONMOVE:
		{
			user -> m_item.at(0) -> heal(user -> m_pokemon.at(user -> m_currentPokemon));
			break;
		}

	case SUPERPOTIONMOVE:
		{
			user -> m_item.at(1) -> heal(user -> m_pokemon.at(user -> m_currentPokemon));
			break;
		}

	}

	bool check = CheckIfAllFainted(ash);

	if (check == true) {
		return WON;
	}

	CheckIfNeedSwitch(ash);

	return PLAY;
}