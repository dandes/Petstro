#ifndef GAMEPLAY
#define GAMEPLAY

#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

/* ****************************************************************************************************** */
MenuOption CollectPlayerMenuOption(){ // Collects Player menu choices
	char playerChoice[256] = "";
	
	cin.getline(playerChoice, 256, '\n');
	
	switch(playerChoice[0]){
	case '1':
		cout << endl << "~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.[ Starting Solo Play! ]~.~.~.~.~.~.~.~.~.~.~.~.~.~" << endl;  // Lets player know he is playing alone
		return MENU_SOLO_PLAY;
		break;
	case '2':
		cout << endl << "~.~.~.~.~.~.~.~.~.~.~.~.~.[ Starting Two Player Game! ]~.~.~.~.~.~.~.~.~.~.~.~.~" << endl;
		return MENU_TWO_PLAYERS;
		break;
	case 'X':
	case 'x':
		cout  << endl << "Good Bye!" << endl;
		return MENU_END;
		break;
	default:
		cout << "What option is that?" << endl << endl;
		return MENU_INVALID;
		break;
	}
}

/* ****************************************************************************************************** */
void DisplayGameMenuOptionsScreen(int roundNumber, Player *player1_ptr, Player *player2_ptr){ // Displays Options after first round is played
		cout << endl << endl << "=[Round " << roundNumber << "]===================================================================";
			if(roundNumber < 10){cout << "===" << endl;			        // These big IF statements keeps the graphics lining up in regardless of
			} 
			
			else if(roundNumber < 100){cout << "==" << endl;	        // the digits on the line
			} 
			else {cout << "=" << endl;}
		
		
		// This block needs to take into account the number of chars in the name
		cout << "| Score: -- " << player1_ptr->playername << ": " << player1_ptr->score << " -- " << player2_ptr->playername << ": " << player2_ptr->score << " --";
		
		int lengthOfLine = 24 + player1_ptr->playername.length() + player2_ptr->playername.length();  // now we calculate the number of chars in the line we just wrote
		
		if(player1_ptr->score < 10){lengthOfLine = lengthOfLine + 1;     // Now we add the number of chars in the digits of the score
		} else if(player1_ptr->score < 100){lengthOfLine = lengthOfLine + 2;
		} else {lengthOfLine = lengthOfLine + 3;}
		
		if(player2_ptr->score < 10){lengthOfLine = lengthOfLine + 1;
		} else if(player2_ptr->score < 100){lengthOfLine = lengthOfLine + 2;
		} else {lengthOfLine = lengthOfLine + 3;}
		
		for(int i=0; i < 80 - lengthOfLine; i++){                       // We print the necessary number of spaces
			cout << " ";
		}
		
		cout << "|" << endl;                                            // And, finally, we print the '|' at the end
		
		cout << "|                                                                              |" << endl
		     << "| Choose an option:  [1] Rock  [2] Paper  [3] Scissors  [X] Quit               |" << endl
		     << "| Option: ";
}

/* ****************************************************************************************************** */
void DisplayPostChoiceScreen(Player *player1_ptr, Player *player2_ptr){
	string player1choice_txt, player2choice_txt = "";
	
	switch(player1_ptr->gameOption){
	case GAME_ROCK:
		player1choice_txt = "ROCK";
		break;
	case GAME_PAPER:
		player1choice_txt = "PAPER";
		break;
	case GAME_SCISSORS:
		player1choice_txt = "SCISSORS";
		break;
	default:
		break;
	}
	
	switch(player2_ptr->gameOption){
	case GAME_ROCK:
		player2choice_txt = "ROCK";
		break;
	case GAME_PAPER:
		player2choice_txt = "PAPER";
		break;
	case GAME_SCISSORS:
		player2choice_txt = "SCISSORS";
		break;
	default:
		break;
	}
	
	string player1Line = " " + player1_ptr->playername + " chose: " + player1choice_txt + " ";
	string player2Line = " " + player2_ptr->playername + " chose: " + player2choice_txt + " ";
	
	int player1Line_len = player1Line.length();
	if(player1Line_len % 2){player1Line_len = player1Line_len +1;}      // If odd number, add one
	for(int i=0; i < 20 - (player1Line_len / 2); i++){
		cout << "=";
	}
	
	cout << player1Line;
	for(int i=0; i < 20 - (player1Line_len / 2); i++){
		cout << "=";
	}
	if(player1Line.length()%2){cout << "=";}
	
	int player2Line_len = player2Line.length();
	if(player2Line_len % 2){player2Line_len = player2Line_len +1;} // If odd
	for(int i=0; i < 20 - (player2Line_len / 2); i++){
		cout << "=";
	}
	
	cout << player2Line;
	for(int i=0; i < 20 - (player2Line_len / 2); i++){
		cout << "=";
	}
	if(player2Line.length()%2){cout << "=";}
	
	cout << endl;
	

}

/* ****************************************************************************************************** */
GameplayOption CollectPlayerGameOption(){  //Gameplay Options with a choice to END game
	char playerChoice[256] = "";
	
	cin.getline(playerChoice, 256, '\n');

	switch(playerChoice[0]){
	case '1':
		return GAME_ROCK;
		break;
	case '2':
		return GAME_PAPER;
		break;
	case '3':
		return GAME_SCISSORS;
		break;
	case 'X':
		return GAME_END;
		break;
	case 'x':
		return GAME_END;
		break;
	default:
		return GAME_INVALID;
		break;
	}
	
	return GAME_INVALID;
}

/* ****************************************************************************************************** */
int chooseWinner(GameplayOption choice1, GameplayOption choice2){
	
	//cout << "DEBUG: choice1: " << choice1 << "KK" << endl;
	switch(choice1){
	case GAME_ROCK:
		if(choice2 == GAME_ROCK){return 0;}
		if(choice2 == GAME_PAPER){return 2;}
		if(choice2 == GAME_SCISSORS){return 1;}
		break;
	case GAME_PAPER:
		if(choice2 == GAME_ROCK){return 1;}
		if(choice2 == GAME_PAPER){return 0;}
		if(choice2 == GAME_SCISSORS){return 2;}
		break;
	case GAME_SCISSORS:
		if(choice2 == GAME_ROCK){return 2;}
		if(choice2 == GAME_PAPER){return 1;}
		if(choice2 == GAME_SCISSORS){return 0;}
		break;
	default:
		cout << "ERROR: Wierd value on choosingWinner!" << endl;
		return 0;
		break;
	}
	
	return 1;
}

#endif
