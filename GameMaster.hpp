#ifndef GAMEMASTER
#define GAMEMASTER

#include <iostream>
#include <string>

#include "Player.hpp"

using namespace std;

/* ****************************************************************************************************** */
class GameMaster{                   // Contains all game information, including players, board, and rule logic
	public:
	Player *player1_ptr;            //need pointers to player classes
	Player *player2_ptr;
	int roundNumber;                //number of rounds played
	
	GameMaster(Player*, Player*);
};

GameMaster :: GameMaster(Player *player_ptr, Player *another_player_ptr){
	roundNumber = 0;
	player1_ptr = player_ptr;
	player2_ptr = another_player_ptr;
}

#endif
