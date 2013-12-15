#include "header.h"
#include "Game.h"
#include "Intro.h"
#include "Rules.h"
#include "Player.h"
#include "Battle.h"
#include "Item.h"

// The game is originally UNITIALIZED, since it is
// just starting
Game::GameState Game::stateOfGame = UNINITIALIZED;
sf::RenderWindow Game::window;

Player Game::user;
Player Game::ash;

DisplayedObject Game::roomBackground;
DisplayedObject Game::exclamationMark;

// Starts the game
void Game::Start()
{
	// Simple control check
	if(stateOfGame != UNINITIALIZED)
		return;

	// Loads
	window.create(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Poke Game");

	roomBackground.Load("images/RoomBackground.jpg");
	exclamationMark.Load("images/exclamationMark.png");
	exclamationMark.SetPosition(ASH_X + 2, ASH_Y - 30);

	user.Load("images/User.png");
	user.SetPosition(USER_X, USER_Y);

	ash.Load("images/User.png");
	ash.SetPosition(ASH_X, -50);

	stateOfGame = Game::INTRO;

	// Loops the game until the game state
	// has changed to EXITING
	while(stateOfGame != Game::EXITING)
	{
		Loop();
	}

	window.close();
}

// Checks what scene/cutscene the state is in
// and plays that scene
void Game::Loop()
{	

	switch(stateOfGame) {

	case Game::ROOM:
		{
			ShowRoom();
			break;
		}

	case Game::ROOMIN:
		{
			ShowRoomIn();
			break;
		}

	case Game::ROOMOUT:
		{
			ShowRoomOut();
			break;
		}

	case Game::BATTLE:
		{
			ShowBattle();
			break;
		}

	case Game::INTRO:
		{
			ShowIntro();
			break;
		}

	case Game::RULES:
		{
			ShowRules();
			break;
		}

	default:
		{
			break;
		}
	}
}

// Displays the intro
void Game::ShowIntro()
{
	Intro Intro;
	window.clear();
	Intro.show(window);

	// Transistions into ROOMIN
	stateOfGame = RULES;
}

// Displays the rules
void Game::ShowRules()
{
	Rules Rule;
	window.clear();
	Rule.show(window);

	// Transistions into ROOMIN
	stateOfGame = ROOMIN;
}


// Displays the room
void Game::ShowRoom()
{
	// Draws everything to the room
	DrawAllRoom();

	sf::Event currentEvent;
	while(true)
	{
		window.waitEvent(currentEvent);

		// If close is clicked then close the screen
		if(currentEvent.type == sf::Event::Closed) { 
			stateOfGame = EXITING;
		}

		// Move the user
		if(currentEvent.type == sf::Event::KeyPressed)
		{
			if(currentEvent.key.code == sf::Keyboard::Space) {

				stateOfGame = Game::BATTLE;
				return;

			} else if(currentEvent.key.code == sf:: Keyboard::Up) {

				MovePlayer(UP, &user);

			} else if(currentEvent.key.code == sf:: Keyboard::Left) {

				MovePlayer(LEFT, &user);

			} else if(currentEvent.key.code == sf:: Keyboard::Right) {

				MovePlayer(RIGHT, &user);

			} else if(currentEvent.key.code == sf:: Keyboard::Down) {

				MovePlayer(DOWN, &user);

			}

		}

	}

}

// Displays the Ash walking in cutscene
void Game::ShowRoomIn()
{
	In();
	// Transitions into the room scene
	stateOfGame = ROOM;

}

// Displays the Ash walking out cutscene
void Game::ShowRoomOut()
{
	Out();
	// Transitions into the ash walking
	// in cutscene
	stateOfGame = ROOMIN;
}

// Shows a new battle between Ash and the user
void Game::ShowBattle()
{
	Battle battle;
	battle.show(window);
	stateOfGame = ROOMOUT;
}

// Draws everything that is in the room
void Game::DrawAllRoom() {

	window.clear();
	roomBackground.Draw(window);
	user.Draw(window);
	ash.Draw(window);
	window.display();

}

// Helper for Ash walking in
void Game::In() {

	while(ash.m_y < ASH_Y) {
		MovePlayer(DOWN, &ash);
	}

	exclamationMark.Draw(window);
	window.display();
	sf::sleep(sf::milliseconds(1000));

}

// Helper for Ash walking out
void Game::Out() {

	while(ash.m_y > 30) {

		MovePlayer(UP, &ash);

	}
}

// Moves the legs back and forth of the player. It takes
// four steps total
void Game::MovePlayer (Direction direction, Player* movingPlayer) {

	WalkHelper(direction, MOVE_RIGHT_LEG, movingPlayer);
	sf::sleep(sf::milliseconds(100));

	WalkHelper(direction, MOVE_LEFT_LEG, movingPlayer);
	sf::sleep(sf::milliseconds(100));

	WalkHelper(direction, MOVE_RIGHT_LEG, movingPlayer);
	sf::sleep(sf::milliseconds(100));

	WalkHelper(direction, MOVE_LEFT_LEG, movingPlayer);
	sf::sleep(sf::milliseconds(100));

	WalkHelper(direction, STILL, movingPlayer);

}

// Draws the single step to the window
void Game::WalkHelper (Direction direction, Action action, Player* movingPlayer) {

	WalkHelperII(direction, action, movingPlayer);
	movingPlayer -> Move(direction);
	DrawAllRoom();
}

// Changes the step to be the correct part of the sprite sheet
void Game::WalkHelperII(Direction direction, Action action, Player* movingPlayer) {

	if(direction == UP) {

		if (action == MOVE_LEFT_LEG) {

			movingPlayer -> m_intRect = sf::IntRect(32, 96, 32, 32);

		} else if (action == MOVE_RIGHT_LEG) {

			movingPlayer -> m_intRect = sf::IntRect(96, 96, 32, 32);

		} else {

			movingPlayer -> m_intRect = sf::IntRect(64, 96, 32, 32);

		}

	} else if (direction == DOWN) {

		if (action == MOVE_LEFT_LEG) {

			movingPlayer -> m_intRect = sf::IntRect(32, 0, 32, 32);

		} else if (action == MOVE_RIGHT_LEG) {

			movingPlayer -> m_intRect = sf::IntRect(96, 0, 32, 32);

		} else {

			movingPlayer -> m_intRect = sf::IntRect(64, 0, 32, 32);

		}

	} else if (direction == LEFT) {

		if (action == MOVE_LEFT_LEG) {

			movingPlayer -> m_intRect = sf::IntRect(32, 32, 32, 32);

		} else if (action == MOVE_RIGHT_LEG) {

			movingPlayer -> m_intRect = sf::IntRect(96, 32, 32, 32);

		} else {

			movingPlayer -> m_intRect = sf::IntRect(64, 32, 32, 32);

		}

	} else if (direction == RIGHT) {

		if (action == MOVE_LEFT_LEG) {

			movingPlayer -> m_intRect = sf::IntRect(32, 64, 32, 32);

		} else if (action == MOVE_RIGHT_LEG) {

			movingPlayer -> m_intRect = sf::IntRect(96, 64, 32, 32);

		} else {

			movingPlayer -> m_intRect = sf::IntRect(64, 64, 32, 32);

		}

	}
}