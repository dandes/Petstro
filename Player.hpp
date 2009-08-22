#ifndef PLAYER
#define PLAYER

#include <cstdlib> 

using namespace std;

/* ****************************************************************************************************** */
class Player{                   // Contains all player Information
	public:
	string playername;          // player name
	bool human;                 // if the player is human or AI
	int score;                  // player score
	GameplayOption gameOption;  // player hand (Did he choose rock, paper, or scissors?)
	
	Player();
	GameplayOption AutoChooseGameOption();
};

/* ****************************************************************************************************** */
Player :: Player(){
	playername = "";
	human = true;    
	score = 0;
	gameOption = GAME_INVALID;
}

/* ****************************************************************************************************** */
// Choses a hand when player is not a human.  Right now just chooses randomly.
GameplayOption Player :: AutoChooseGameOption(){
	int random_integer = (rand() % 3) + 1;
			
	switch(random_integer){
	case 1:
		gameOption = GAME_ROCK;
		return GAME_ROCK;
		break;
	case 2:
		gameOption = GAME_PAPER;
		return GAME_PAPER;
		break;
	case 3:
		gameOption = GAME_SCISSORS;
		return GAME_SCISSORS;
		break;
	default:
		cout << "ERROR: The AI returned some wierd value.." << endl;
		break;
	}
	return GAME_INVALID;
}




#endif
