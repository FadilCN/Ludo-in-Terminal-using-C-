#include "functions.h"
#include <random>
#include <chrono>
#include <unistd.h>
#include <cstdlib>

mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dist(1, 6);

PawnR R1(6, 0), R2(6, 0), R3(6, 0), R4(6, 0);
PawnG G1(0, 8), G2(0, 8), G3(0, 8), G4(0, 8);
PawnB B1(8, 14), B2(8, 14), B3(8, 14), B4(8, 14);
PawnY Y1(14, 6), Y2(14, 6), Y3(14, 6), Y4(14, 6);

int win[]= {0,0,0,0};
const int MAX_STEPS = 62;


int rollDice() {
	return dist(gen);
	
}

int incrPlayerId(int id) {
	id++;
	if (id >= 4) id = 0;
	return id;
}

void draw(string (&board)[15][15]) {
	int i, j;

	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			board[i][j] = " ";
		}
	}

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			board[i][j] = RED;
			board[i + 9][j] = YELLOW;
			board[i][j + 9] = GREEN;
			board[i + 9][j + 9] = BLUE;
			board[6][j] = BLACK;
			board[6][j + 9] = BLACK;
			board[8][j] = BLACK;
			board[8][j + 9] = BLACK;
			board[7][j] = RED;
			board[7][j + 9] = BLUE;
			board[i][7] = GREEN;
			board[i + 9][7] = YELLOW;
			board[i][6] = BLACK;
			board[i][8] = BLACK;
			board[i + 9][8] = BLACK;
			board[i + 9][6] = BLACK;
		}
	}

	board[6][7] = GREEN;
	board[7][8] = BLUE;
	board[8][7] = YELLOW;
	board[7][6] = RED;
	board[6][1] = RED;
	board[7][7] = BLACK;
	board[6][6] = BLACK;
	board[6][8] = BLACK;
	board[8][6] = BLACK;
	board[8][8] = BLACK;
	board[7][0] = BLACK;
	board[7][14] = BLACK;
	board[0][7] = BLACK;
	board[14][7] = BLACK;
	board[13][6] = YELLOW;
	board[1][8] = GREEN;
	board[8][13] = BLUE;

	board[1][1] = "R1";
	board[1][4] = "R2";
	board[4][1] = "R3";
	board[4][4] = "R4";
	board[1][10] = "G1";
	board[1][13] = "G2";
	board[4][10] = "G3";
	board[4][13] = "G4";
	board[10][1] = "Y1";
	board[10][4] = "Y2";
	board[13][1] = "Y3";
	board[13][4] = "Y4";
	board[10][10] = "B1";
	board[10][13] = "B2";
	board[13][10] = "B3";
	board[13][13] = "B4";
	
}

void print(string (&board)[15][15]) {
    	   cout << "\033[H";
		sleep(1);
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (board[i][j] == RED || board[i][j] == BLUE || board[i][j] == YELLOW || board[i][j] == GREEN || board[i][j] == BLACK) {
				cout << "[" << board[i][j] << "    " << RESET << "]"; 
			} else {
				cout << "[ " << board[i][j] << " ]";
			}
		}
		cout << endl;
		
	}


}

void waitForEnter() { 
      
        cout<<"press ENTER to Roll Dice  >>>";
        cin.get();
}

void turns(int color, int pawn_no, string (&board)[15][15]) {

	string pawn_num;

	switch (color) {
	case 0: {
		PawnR* p;
		if (pawn_no == 1) p = &R1;
		else if (pawn_no == 2) p = &R2;
		else if (pawn_no == 3) p = &R3;
		else p = &R4;

		pawn_num = "R" + to_string(pawn_no + 1); 
		p->move(board, pawn_num);
		break;
	}
	case 1: {
		PawnG* p;
		if (pawn_no == 1) p = &G1;
		else if (pawn_no == 2) p = &G2;
		else if (pawn_no == 3) p = &G3;
		else p = &G4;

		pawn_num = "G" + to_string(pawn_no + 1); 
		break;
	}
	case 2: {
		PawnB* p;
		if (pawn_no == 1) p = &B1;
		else if (pawn_no == 2) p = &B2;
		else if (pawn_no == 3) p = &B3;
		else p = &B4;

		pawn_num = "B" + to_string(pawn_no + 1); 
		p->move(board, pawn_num);
		break;
	}
	case 3: {
		PawnY* p;
		if (pawn_no == 1) p = &Y1;
		else if (pawn_no == 2) p = &Y2;
		else if (pawn_no == 3) p = &Y3;
		else p = &Y4;

		pawn_num = "Y" + to_string(pawn_no + 1); 
		p->move(board, pawn_num);
		break;
	}
	default:
		cout << "Invalid color" << endl;
		break;
	}
}
void fill(int playerId,int* current_player[4], int index, string (&board)[15][15])
{
    if (current_player[playerId][index] == 1) {
        switch (playerId) {
            case 0: // RED
                if (index == 0) {board[1][1] = BLACK;cout<<endl<<"here";}
                else if (index == 1) board[1][4] = BLACK;
                else if (index == 2) board[4][1] = BLACK;
                else if (index == 3) board[4][4] = BLACK;
                break;

            case 1: // BLUE
                 if (index == 0) board[1][10] = BLACK;
                else if (index == 1) board[1][13] = BLACK;
                else if (index == 2) board[4][10] = BLACK;
                else if (index == 3) board[4][13] = BLACK;
                break;
            case 2: // GREEN
               
                 if (index == 0) board[10][10] = BLACK;
                else if (index == 1) board[10][13] = BLACK;
                else if (index == 2) board[13][10] = BLACK;
                else if (index == 3) board[13][13] = BLACK;
                break;


            case 3: // YELLOW
                if (index == 0) board[10][1] = BLACK;
                else if (index == 1) board[10][4] = BLACK;
                else if (index == 2) board[13][1] = BLACK;
                else if (index == 3) board[13][4] = BLACK;
                break;
        }
    }
}





void checkWinCondition(int playerId, int* current_player[4], int win[4], int pawn) {

	if(current_player[playerId][pawn] == 62)
	{
		win[playerId]++;
		cout << "--- Player " << playerId + 1 << " has " << win[playerId] << " pawn(s) home! ---" << endl;
		sleep(1);

		current_player[playerId][pawn] = 99;
	}


	if(win[playerId] == 4) {
		cout << "GAME OVER! Player " << playerId + 1 << " WINS" << endl;
		sleep(3); 
		exit(0);  
	}
}


void releasePawn(int playerId, int &available, string (&board)[15][15], int* current_player[4])
{
	cout << "Releasing a new pawn..." << endl;
	sleep(1);
	turns(playerId, available, board);
        current_player[playerId][available] = 1;
	cout << "\033[H\033[J";
        fill(playerId,current_player ,available, board);
	print(board);
	checkWinCondition(playerId, current_player, win, available); // Check win
	available++;
}

void movePawn(int playerId, int pawnIndex, int num, string (&board)[15][15], int* current_player[4])
{
	cout << "Moving pawn " << pawnIndex << " by " << num << " steps..." << endl;
	cout << "\033[H\033[J";
	for (int i = 0; i < num; i++) {
		turns(playerId, pawnIndex, board);
		 
		print(board);
	}
	current_player[playerId][pawnIndex] += num;
	checkWinCondition(playerId, current_player, win, pawnIndex);
	sleep(1);
}


//  for rolling a 6
void handleSixRoll(int playerId, int &available, int num, string (&board)[15][15], int* current_player[4])
	{
		int selection = 0;
		sleep(1);
		cout << "Enter 1 to release a new pawn, or 2 to move an existing pawn: ";
		cin >> selection;
                cin.ignore(1000, '\n');

		switch (selection) {
		case 1:
            if (available < 4) {
			    releasePawn(playerId, available, board, current_player);
            } else {
                cout << "All pawns are already out! You must move a pawn." << endl;
                selection = 2; // Force case 2
            }
			break;

		case 2:
			//  Only one pawn available 
			if (available == 1) {
       
				if (current_player[playerId][0] + num > MAX_STEPS || current_player[playerId][0] == 99) {
					cout << "Can't move this pawn." << endl;
					if (available < 4)
						releasePawn(playerId, available, board, current_player);
					break;
				}
				cout << "Automatically moving your only pawn." << endl;
				movePawn(playerId, 0, num, board, current_player);
				checkWinCondition(playerId, current_player, win, 0);
				break;
			}

			//  Multiple pawns available 
			{
				bool anyMovable = false;
				for (int i = 0; i < available; i++) {
					if (current_player[playerId][i] + num <= MAX_STEPS && current_player[playerId][i] != 99)
						anyMovable = true;
				}

				if (!anyMovable) {
					cout << "No movable pawns." << endl;
					if (available < 4)
						releasePawn(playerId, available, board, current_player);
					break;
				}

				int choice;
				while (true) {
					cout << "Choose which pawn to move (1 to " << available << "): ";
					cin >> choice;
                                        cin.ignore(1000, '\n');
					choice--;
					if (choice < 0 || choice >= available) {
						cout << "Invalid choice! Try again." << endl;
						continue;
					}
                  
					if (current_player[playerId][choice] + num > MAX_STEPS || current_player[playerId][choice] == 99) {
						cout << "Can't move this pawn, choose another." << endl;
						continue;
					}
					break;
				}

				movePawn(playerId, choice, num, board, current_player);
				break;
			}

		default:
			cout << "Invalid selection!" << endl;
			break;
		}
	}