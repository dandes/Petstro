#ifndef PLAYER
#define PLAYER

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

#endif
