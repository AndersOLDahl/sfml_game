#pragma once
#include "Header.h"
#include <vector>

// Forward declerations
class DisplayedObject;
class Player;

class Pokemon;
class Fire;
class Grass;
class Water;
class Item;

class Battle;
class Intro;
class Game;

class Trainer;
class PlayTurn;

// Represents the Game
class Game
{
public:
	// Starts the game
	static void Start();

private:

	// State of the game - the dfferent scenes, cutscenes, etc
	enum GameState { UNINITIALIZED, INTRO, RULES, ROOM, ROOMIN, ROOMOUT, BATTLE, EXITING };

	// Helper for moving the legs of a player
	enum Action { STILL, MOVE_LEFT_LEG, MOVE_RIGHT_LEG };

	// State of the game
	static GameState stateOfGame;

	// Window of the game
	static sf::RenderWindow window;

	// Players of the game
	static Player user;
	static Player ash;

	// Displayed images
	static DisplayedObject roomBackground;
	static DisplayedObject exclamationMark;

	// Loops the game until the player quits
	static void Loop();
	
	// Show the different scenes/cutscenes
	static void ShowIntro();
	static void ShowRules();
	static void ShowRoom();
	static void ShowRoomIn();
	static void ShowRoomOut();
	static void ShowBattle();

	// Draw the player, ash, and background
	static void DrawAllRoom();

	// Helps with the in and out cutscenes
	static void In();
	static void Out();

	// Helpers for walking. Uses a sprite sheet to imitate a character
	// moving
	static void MovePlayer (Direction direction, Player* movingPlayer);
	static void WalkHelper (Direction direction, Action action, Player* movingPlayer);
	static void WalkHelperII (Direction direction, Action action, Player* movingPlayer);

};