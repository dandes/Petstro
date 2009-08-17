// RockPaperScissors - A Rock, Paper, Scissors game; either two-player or solo (against the computer).


#include <iostream>
#include "GameplayOpt_002.hpp"

using namespace std;

void DisplayIntroScreen(){ // Displays Introduction screen
	cout << "================================================================================" << endl
	     << "|               R O C K         P A P E R        S C I S S O R S               |" << endl
	     << "|                 -An Authentic Rock Paper Scissors Simulator-                 |" << endl
	     << "|                                                                              |" << endl
	     << "-^--^---^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--" << endl;
}

void DisplayMenuOptionsScreen(){ // Displays Menu Options for player
	cout << "Choose an option:  [1] Solo Play  [2] Two Players  [X] Exit" << endl
		 << "Option: ";
}

MenuOption SelectMainMenuOpt(Player *player2_ptr){
	MenuOption mainMenuOption = MENU_INVALID;
	
	while(mainMenuOption == MENU_INVALID){	// loop until player selects valid option
		DisplayMenuOptionsScreen();                // Display Main Menu
		mainMenuOption = CollectPlayerMenuOption();	// collect and validate menu option
	}
	
	if(mainMenuOption == MENU_SOLO_PLAY){player2_ptr->human = false;}
	
	return mainMenuOption;
}

bool StartGame(Player *player1_ptr, Player *player2_ptr){
	int roundNumber = 0;
	bool areWeStillPlaying = true;
	GameplayOption gameOption = GAME_INVALID;
		while(1){
		// If computer opponent, computer greets player
		
		roundNumber++;
		
		while(gameOption == GAME_INVALID){
			DisplayGameMenuOptionsScreen(roundNumber, player1_ptr, player2_ptr);
			gameOption = CollectPlayerGameOption();	// Player chooses Rock, Paper, Scissors, or finish
			if(gameOption == GAME_INVALID){cout << "That was not a valid option!! Try again." << endl;}
			if(gameOption == GAME_END){
				cout << "================================[ Game Canceled! ]==============================" << endl << endl << endl << endl;
				return false;
			}
		}
		if(gameOption == GAME_END){  // Ends game
			areWeStillPlaying = false;
			break;
		}
		
		player1_ptr->gameOption = gameOption;
		player2_ptr->AutoChooseGameOption();
		
		DisplayPostChoiceScreen(player1_ptr, player2_ptr);
		
		
		switch(chooseWinner(player1_ptr->gameOption, player2_ptr->gameOption)){
			case 0:
				cout << endl << "                                   !! Tie !!" << endl << "                               No Points Awarded!" << endl;
				break;
			case 1:
				cout << endl << "                              !! " << player1_ptr->playername << " wins !!" << endl;
				player1_ptr->score++;
				break;
			case 2:
				cout << endl << "                              !! " << player2_ptr->playername << " wins !!" << endl;
				player2_ptr->score++;
				break;
			default:
				cout << "ERROR: chooseWinner returned some invalid value!!" << endl;
		}
		gameOption = GAME_INVALID;
	}
	
	return true;
}

int main(){
	
	Player Player1, Player2;
	Player1.playername = "Aunt Jemima";
	Player2.playername = "Uncle Phil";
	//int roundNumber = 0;
	
	bool gameOver = false;
	while(!gameOver){
		// Display RockPaperScissors intro screen
		DisplayIntroScreen();
		
		// Display Main Menu and wait for options
		MenuOption mainMenuOption = MENU_INVALID;
		mainMenuOption = SelectMainMenuOpt(&Player2);
		
		switch(mainMenuOption){
			case MENU_SOLO_PLAY:
			case MENU_TWO_PLAYERS:
				// Start Gameplay
				StartGame(&Player1, &Player2);
				break;
			case MENU_END:
				return 0;
				break;
			default:
				cout << "ERROR: This should never happen!!" << endl;
				break;
		}
	}
	
	
	return 0;
}
