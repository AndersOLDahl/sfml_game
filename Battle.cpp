#include "Battle.h"
#include "Trainer.h"
#include "PlayTurn.h"

// Initalizes stateOfGame to play
BattleState Battle::stateOfGame = PLAY;

Trainer Battle::user;
Trainer Battle::ash("Ash");

Fire Battle::uF1;
Fire Battle::uF2;
Water Battle::uW3;
Water Battle::uW4;
Grass Battle::uG5;
Grass Battle::uG6;
Item Battle::uI1("Potion", 20);
Item Battle::uI2("SuperPotion", 50);

Fire Battle::aF1;
Fire Battle::aF2;
Water Battle::aW3;
Water Battle::aW4;
Grass Battle::aG5;
Grass Battle::aG6;

DisplayedObject Battle::rain;
DisplayedObject Battle::sun;
DisplayedObject Battle::sand;

sf::RectangleShape Battle::uH(sf::Vector2f(200, 50));
sf::RectangleShape Battle::aH(sf::Vector2f(200, 50));

// Shows the battle
void Battle::show(sf::RenderWindow &window)
{
	// Loads the different backgrounds of the battle scene
	sf::Texture battleT;
	if(battleT.loadFromFile("images/BattleBackground.png") != true) {
		return;
	}
	sf::Sprite battle(battleT);

	sf::Texture battleMovesT;
	if(battleMovesT.loadFromFile("images/BattleBackgroundMoves.png") != true) {
		return;
	}
	sf::Sprite battleMoves(battleMovesT);

	sf::Texture battleSwitchT;
	if(battleSwitchT.loadFromFile("images/BattleBackgroundPokemon.png") != true) {
		return;
	}
	sf::Sprite battleSwitch(battleSwitchT);

	sf::Texture battleItemsT;
	if(battleItemsT.loadFromFile("images/BattleBackgroundItems.png") != true) {
		return;
	}
	sf::Sprite battleItems(battleItemsT);

	stateOfGame = PLAY;
	
	// Initalizes/resets trainers
	InitalizeLoads();
	InitalizeUser();
	ResetAsh();

	while(stateOfGame == PLAY)
	{

		// Displays the health of the Pokemon in the CMD each loop
		DisplayAllHealth();

		// Draws everything to the screen and displays it
		// each loop
		DrawAll(window, &battle);

		sf::Event currentEvent;
		while(true)
		{
			window.waitEvent(currentEvent);

			// Exit the screen if closed is clicked
			if(currentEvent.type == sf::Event::Closed) { 
				exit(0);
			}

			// Decide on Moves, Switch, Items, and Run
			if(currentEvent.type == sf::Event::KeyPressed)
			{
				if(currentEvent.key.code == sf::Keyboard::Num1) {

					ShowMove(window, &battleMoves);

				} else if(currentEvent.key.code == sf:: Keyboard::Num2) {

					ShowPokemon(window, &battleSwitch);

				} else if(currentEvent.key.code == sf:: Keyboard::Num3) {

					ShowItem(window, &battleItems);

				} else if(currentEvent.key.code == sf:: Keyboard::Num4) {

					stateOfGame = LOST;

				} 

			}

			break;

		}

	}

}

// Displays the health of all the Pokemon in the CMD
void Battle::DisplayAllHealth() {

	// Clears the screen and displays the health
	system("CLS");
	user.DisplayHealth();
	ash.DisplayHealth();

}

// Draws everything to the screen and displays it
void Battle::DrawAll(sf::RenderWindow &window, sf::Sprite * background) {

	window.clear();
	window.draw(*background);
	user.Draw(window);
	ash.Draw(window);
	DrawWeather(window);
	window.draw(uH);
	window.draw(aH);

	uH.setScale(((float)user.m_pokemon.at(user.m_currentPokemon) -> m_health)
		/ 100, 1);
	aH.setScale(((float)ash.m_pokemon.at(ash.m_currentPokemon) -> m_health)
		/ 100, 1);

	window.display();

}

// Draws the weather
void Battle::DrawWeather(sf::RenderWindow &window) {

	if (Pokemon::weather == SUNNYDAY) {

		sun.Draw(window);

	} else if (Pokemon::weather == RAINDANCE) {

		rain.Draw(window);

	} else if (Pokemon::weather == SANDSTORM) {

		sand.Draw(window);

	}

}

// Loads the images
void Battle::InitalizeLoads() {

	rain.Load("images/RainDance.png");

	sun.Load("images/SunnyDay.png");

	sand.Load("images/SandStorm.png");

	uF1.Load("images/Charmander.png");
	uF1.SetPosition(POKEMON_X_U, POKEMON_Y_U);
	uF2.Load("images/Charmander.png");
	uF2.SetPosition(POKEMON_X_U, POKEMON_Y_U);
	uW3.Load("images/Squirtle.png");
	uW3.SetPosition(POKEMON_X_U, POKEMON_Y_U);
	uW4.Load("images/Squirtle.png");
	uW4.SetPosition(POKEMON_X_U, POKEMON_Y_U);
	uG5.Load("images/Bulbasaur.png");
	uG5.SetPosition(POKEMON_X_U, POKEMON_Y_U);
	uG6.Load("images/Bulbasaur.png");
	uG6.SetPosition(POKEMON_X_U, POKEMON_Y_U);

	aF1.Load("images/Charmander.png");
	aF1.SetPosition(POKEMON_X_A, POKEMON_Y_A);
	aF2.Load("images/Charmander.png");
	aF2.SetPosition(POKEMON_X_A, POKEMON_Y_A);
	aW3.Load("images/Squirtle.png");
	aW3.SetPosition(POKEMON_X_A, POKEMON_Y_A);
	aW4.Load("images/Squirtle.png");
	aW4.SetPosition(POKEMON_X_A, POKEMON_Y_A);
	aG5.Load("images/Bulbasaur.png");
	aG5.SetPosition(POKEMON_X_A, POKEMON_Y_A);
	aG6.Load("images/Bulbasaur.png");
	aG6.SetPosition(POKEMON_X_A, POKEMON_Y_A);

	uH.setPosition(400, 350);
	aH.setPosition(800, 50);
	uH.setFillColor(sf::Color(255, 0, 0));
	aH.setFillColor(sf::Color(255, 0, 0));

}

// Initalizes/resets the vector of the Pokemon
// and Items for the user
void Battle::InitalizeUser() {

	user.m_pokemon.clear();
	user.m_item.clear();

	user.m_currentPokemon = 0;

	user.m_pokemon.push_back(&uF1);
	user.m_pokemon.push_back(&uF2);
	user.m_pokemon.push_back(&uW3);
	user.m_pokemon.push_back(&uW4);
	user.m_pokemon.push_back(&uG5);
	user.m_pokemon.push_back(&uG6);

	user.m_item.push_back(&uI1);
	user.m_item.push_back(&uI2);

	for(unsigned int i = 0; i < user.m_pokemon.size(); i++) {
		user.m_pokemon.at(i) -> m_health = 100;
		user.m_pokemon.at(i) -> m_isFainted = false;
	}

	assert (user.m_pokemon.size() == 6);
	assert (user.m_item.size() == 2);

}

// Initalizes the vector of the Pokemon
// and Items for Ash
void Battle::ResetAsh() {

	ash.m_pokemon.clear();

	srand(time(NULL));
	ash.m_currentPokemon = rand() % 6;

	ash.m_pokemon.push_back(&aF1);
	ash.m_pokemon.push_back(&aW3);
	ash.m_pokemon.push_back(&aG5);
	ash.m_pokemon.push_back(&aF2);
	ash.m_pokemon.push_back(&aW4);
	ash.m_pokemon.push_back(&aG6);

	for(unsigned int i = 0; i < ash.m_pokemon.size(); i++) {
		ash.m_pokemon.at(i) -> m_health = 100;
		ash.m_pokemon.at(i) -> m_isFainted = false;
	}

	assert (ash.m_pokemon.size() == 6);
}

// Display the moves
void Battle::ShowMove(sf::RenderWindow &window, sf::Sprite * background) {

	DrawAll(window, background);
	stateOfGame = chooseMove(window);

}

// Chooses a move and plays the whole turn
BattleState Battle::chooseMove(sf::RenderWindow &window) {

	sf::Event currentEvent;
	while(true)
	{
		window.waitEvent(currentEvent);

		// Close the screen if close is clicked
		if(currentEvent.type == sf::Event::Closed) {
			exit(0);
		}

		if(currentEvent.type == sf::Event::KeyPressed)

			if(currentEvent.key.code == sf::Keyboard::Num1) {

				return PlayTurn::PlayTurnWhole(&user, &ash, ATTACK);

			} else if(currentEvent.key.code == sf:: Keyboard::Num2) {

				return PlayTurn::PlayTurnWhole(&user, &ash, SPECIALATTACK);

			} else if(currentEvent.key.code == sf:: Keyboard::Num3) {

				return PlayTurn::PlayTurnWhole(&user, &ash, HEALMOVE);

			} else if(currentEvent.key.code == sf:: Keyboard::Num4) {

				return PlayTurn::PlayTurnWhole(&user, &ash, CHANGEWEATHER);

			}

	}

}

// Display the Pokemon
void Battle::ShowPokemon(sf::RenderWindow &window, sf::Sprite * background) {

	DrawAll(window, background);
	stateOfGame = choosePokemon(window);

}

// Choose a Pokemon and play the whole turn
BattleState Battle::choosePokemon(sf::RenderWindow &window) {

	sf::Event currentEvent;
	while(true)
	{

		window.waitEvent(currentEvent);

		if(currentEvent.type == sf::Event::Closed) {
			exit(0);
		}

		if(currentEvent.type == sf::Event::KeyPressed)
		{
			if(currentEvent.key.code == sf::Keyboard::Num1) {

				user.m_currentPokemon = 0;
				return PlayTurn::PlayTurnWhole(&user, &ash, SWITCH);

			} else if(currentEvent.key.code == sf:: Keyboard::Num2) {

				user.m_currentPokemon = 1;
				return PlayTurn::PlayTurnWhole(&user, &ash, SWITCH);

			} else if(currentEvent.key.code == sf:: Keyboard::Num3) {

				user.m_currentPokemon = 2;
				return PlayTurn::PlayTurnWhole(&user, &ash, SWITCH);

			} else if(currentEvent.key.code == sf:: Keyboard::Num4) {

				user.m_currentPokemon = 3;
				return PlayTurn::PlayTurnWhole(&user, &ash, SWITCH);

			} else if(currentEvent.key.code == sf::Keyboard::Num5) {

				user.m_currentPokemon = 4;
				return PlayTurn::PlayTurnWhole(&user, &ash, SWITCH);

			} else if(currentEvent.key.code == sf::Keyboard::Num6) {

				user.m_currentPokemon = 5;
				return PlayTurn::PlayTurnWhole(&user, &ash, SWITCH);

			}

		}

	}
}

// Display the Items
void Battle::ShowItem(sf::RenderWindow &window,  sf::Sprite * background) {

	DrawAll(window, background);
	stateOfGame = choosePotion(window);

}

// Choose a Potion and play the whole turn
BattleState Battle::choosePotion(sf::RenderWindow &window) {

	sf::Event currentEvent;
	while(true)
	{
		window.waitEvent(currentEvent);

		if(currentEvent.type == sf::Event::Closed) {
			exit(0);
		}

		if(currentEvent.type == sf::Event::KeyPressed)
		{
			if(currentEvent.key.code == sf::Keyboard::Num1) {

				return PlayTurn::PlayTurnWhole(&user, &ash, POTIONMOVE);

			} else if(currentEvent.key.code == sf:: Keyboard::Num2) {

				return PlayTurn::PlayTurnWhole(&user, &ash, SUPERPOTIONMOVE);

			}

		}

	}
}