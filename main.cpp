#include "functions.h"
#include "classes.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int main() {
		int a[] = {0, 0, 0, 0};
		int b[] = {0, 0, 0, 0};
		int c[] = {0, 0, 0, 0};
		int d[] = {0, 0, 0, 0};

		int* current_player[] = {a, b, c, d};
		int playerId = 0;
		int available = 0;
		string board[15][15], pawn_num;
		draw(board);
		cout << "\033[H\033[J";
		print(board);
		int i;
	
		while (true) {

			
			cout << "\n=== Player " << playerId + 1 << "'s turn ===" << endl;
			waitForEnter();
			int loc = 0;

			sleep(1);

			available = 0;
			for (int i = 0; i < 4; i++) {
				if (current_player[playerId][i] != 0) { 
					available++;
					loc = i;
				}
			}

			cout << "You have " << available << " pawn(s) currently on the board." << endl;
			sleep(1);

			int num = rollDice();
			cout << "You rolled a dice: " << num << endl;
			sleep(1);

			if (available == 0 && num == 6) {
				cout << "No pawns on the board, but you rolled a 6! Releasing your first pawn." << endl;
				sleep(2);
				turns(playerId, 0, board);
                                current_player[playerId][0] = 1;
                                fill(playerId,current_player ,0, board);
				cout << "\033[H\033[J";
				print(board);
				sleep(1);
				playerId = incrPlayerId(playerId); 
			}
			else if (available == 0 && num != 6) {
				cout << "No pawns on the board and you did NOT roll a 6. You cannot move any pawn this turn." << endl;
                sleep(2);
				 cout << "\033[H\033[J";
				print(board);
				playerId = incrPlayerId(playerId);
			}

			else if (available >= 1 && num == 6) {
				handleSixRoll(playerId, available, num, board, current_player);
      
				cout << "You rolled a 6, so you get a second turn!" << endl;
				waitForEnter();

				num = rollDice();
				cout << "You rolled a " << num << "!" << endl;

				if(num==6)
				{
					handleSixRoll(playerId, available, num, board, current_player);
					playerId = incrPlayerId(playerId);
				}

				else {
					int choice;
					cout << "Choose which pawn to move (1 to " << available << "): ";

					bool state=true;
					while(state)
					{
						cin >> choice;
                                                cin.ignore(1000, '\n');
						choice--;
                       
						if(current_player[playerId][choice]+num > MAX_STEPS || current_player[playerId][choice] == 99)
						{
							cout<<"Cant move this pawn, choose different pawn"<<endl;
						}
						else {
							state=false;
						}
					}

					if (choice >= 0 && choice < available) {
						 cout << "\033[H\033[J";
						for (i = 0; i < num; i++) {
							turns(playerId, choice, board);
							
							print(board);
						}
						current_player[playerId][choice] += num;
						cout << "Moved pawn " << choice << " by " << num << " steps." << endl;
						checkWinCondition(playerId, current_player, win, choice);
						playerId = incrPlayerId(playerId);
					} else {
						cout << "Invalid choice! No pawn moved." << endl;
					}
				}


			}

			else if (available == 1) {
				cout << "Only one pawn available. Moving pawn 0 by " << num << " steps." << endl;
				sleep(2);
				 cout << "\033[H\033[J";
            
				for (i = 0; i < num; i++) {
					turns(playerId, loc, board);
					print(board);
				}
				current_player[playerId][0] += num;
				checkWinCondition(playerId, current_player, win, 0);
				playerId = incrPlayerId(playerId);
			}
			else if (available > 1 && num != 6) {

				bool anyMovable = false;
				for (int i = 0; i < available; i++) {
                
					if (current_player[playerId][i] + num <= MAX_STEPS && current_player[playerId][i] != 99) {
						anyMovable = true;
						break; 
					}
				}

				if (!anyMovable) {
					cout << "No movable pawns. Skipping turn." << endl;
					sleep(2);
				}
				else {
					int choice;
					cout << "Multiple pawns available. Choose which pawn to move (1 to " << available << "): ";
					bool state = true;

					while (state)
					{
						cin >> choice;
                                                cin.ignore(1000, '\n');
						choice--;
						if (choice < 0 || choice >= available) {
							cout << "Invalid pawn number. Try again." << endl;
						}
                  
						else if (current_player[playerId][choice] + num > MAX_STEPS || current_player[playerId][choice] == 99)
						{
							cout << "Cant move this pawn, choose different pawn" << endl;
						}
						else {
							state = false;
						}
					}

					current_player[playerId][choice] += num;
					 cout << "\033[H\033[J";
					for (i = 0; i < num; i++) {
						turns(playerId, choice, board);
						print(board);
					}
					cout << "Moved pawn " << choice << " by " << num << " steps." << endl;
	 				checkWinCondition(playerId, current_player, win, choice);
					sleep(2);
				}
				playerId = incrPlayerId(playerId);
			}
		}

		return 0;
	}