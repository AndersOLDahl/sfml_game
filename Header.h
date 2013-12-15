#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

#include <assert.h>
// #define NDEBUG // Debug mode on/off for assert statements

enum Direction { DOWN, LEFT, UP, RIGHT };
enum Type { FIRE, GRASS, WATER };
enum Weather { SUNNYDAY, RAINDANCE, SANDSTORM };
enum Action { ATTACK, SPECIALATTACK, HEALMOVE, CHANGEWEATHER, SWITCH, POTIONMOVE, SUPERPOTIONMOVE };
enum BattleState { PLAY, LOST, WON };

#define SCREENWIDTH 1024
#define SCREENHEIGHT 646
#define ASH_X 495
#define ASH_Y (int (SCREENHEIGHT / 2))
#define USER_X 495
#define USER_Y (int ((SCREENHEIGHT / 2) + 200))

#define POKEMON_X_U 0
#define POKEMON_Y_U (int (SCREENHEIGHT * .30))
#define POKEMON_X_A (int (SCREENWIDTH * .35))
#define POKEMON_Y_A 0