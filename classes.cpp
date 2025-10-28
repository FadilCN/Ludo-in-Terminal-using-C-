#include "classes.h"
#include <iostream>
using namespace std;

PawnR::PawnR(int startX, int startY) {
	x = startX;
	y = startY;
	last_x = 0;
	last_y = 0;
	tile_under = BLACK;
	counter = 0;
}

void PawnR::move(string (&board)[15][15], string pawn_no) {
	int count = counter;
	board[last_x][last_y] = tile_under;
	int new_x = x, new_y = y;
	if ((count >= 0 && count < 6) || (count >= 20 && count < 26) || (count >= 12 && count < 14) || (count >= 55 && count < 62))
		new_y++;
	else if ((count >= 6 && count < 12) || (count >= 42 && count < 48) || (count >= 54 && count < 55))
		new_x--;
	else if ((count >= 14 && count < 20) || (count >= 34 && count < 40) || (count >= 26 && count < 28))
		new_x++;
	else if ((count >= 28 && count < 34) || (count >= 48 && count < 54) || (count >= 40 && count < 42))
		new_y--;
	else
		cout << "Movement path finished or invalid count: " << count << endl;

	x = new_x;
	y = new_y;
	counter++;
	tile_under = board[new_x][new_y];
	board[new_x][new_y] = pawn_no;
	last_x = new_x;
	last_y = new_y;
}

PawnG::PawnG(int startX, int startY) {
	x = startX;
	y = startY;
	last_x = 0;
	last_y = 0;
	tile_under = BLACK;
	counter = 0;
}

void PawnG::move(string (&board)[15][15], string pawn_no) {
	int count = counter;
	board[last_x][last_y] = tile_under;
	int new_x = x, new_y = y;
	if ((count >= 0 && count < 6) || (count >= 20 && count < 26) || (count >= 12 && count < 14) || (count >= 55 && count < 62))
		new_x++;
	else if ((count >= 6 && count < 12) || (count >= 42 && count < 48) || (count >= 54 && count < 55))
		new_y++;
	else if ((count >= 14 && count < 20) || (count >= 34 && count < 40) || (count >= 26 && count < 28))
		new_y--;
	else if ((count >= 28 && count < 34) || (count >= 48 && count < 54) || (count >= 40 && count < 42))
		new_x--;
	else
		cout << "Movement path finished or invalid count: " << count << endl;
	x = new_x;
	y = new_y;
	counter++;
	tile_under = board[new_x][new_y];
	board[new_x][new_y] = pawn_no;
	last_x = new_x;
	last_y = new_y;
}

PawnB::PawnB(int startX, int startY) {
	x = startX;
	y = startY;
	last_x = 0;
	last_y = 0;
	tile_under = BLACK;
	counter = 0;
}

void PawnB::move(string (&board)[15][15], string pawn_no) {
	int count = counter;
	board[last_x][last_y] = tile_under;
	int new_x = x, new_y = y;
	if ((count >= 0 && count < 6) || (count >= 20 && count < 26) || (count >= 12 && count < 14) || (count >= 55 && count < 62))
		new_y--;
	else if ((count >= 6 && count < 12) || (count >= 42 && count < 48) || (count >= 54 && count < 55))
		new_x++;
	else if ((count >= 14 && count < 20) || (count >= 34 && count < 40) || (count >= 26 && count < 28))
		new_x--;
	else if ((count >= 28 && count < 34) || (count >= 48 && count < 54) || (count >= 40 && count < 42))
		new_y++;
	else
		cout << "Movement path finished or invalid count: " << count << endl;
	x = new_x;
	y = new_y;
	counter++;
	tile_under = board[new_x][new_y];
	board[new_x][new_y] = pawn_no;
	last_x = new_x;
	last_y = new_y;
}

PawnY::PawnY(int startX, int startY) {
	x = startX;
	y = startY;
	last_x = 0;
	last_y = 0;
	tile_under = BLACK;
	counter = 0;
}

void PawnY::move(string (&board)[15][15], string pawn_no) {
	int count = counter;
	board[last_x][last_y] = tile_under;
	int new_x = x, new_y = y;
	if ((count >= 0 && count < 6) || (count >= 20 && count < 26) || (count >= 12 && count < 14) || (count >= 55 && count < 62))
		new_x--;
	else if ((count >= 6 && count < 12) || (count >= 42 && count < 48) || (count >= 54 && count < 55))
		new_y--;
	else if ((count >= 14 && count < 20) || (count >= 34 && count < 40) || (count >= 26 && count < 28))
		new_y++;
	else if ((count >= 28 && count < 34) || (count >= 48 && count < 54) || (count >= 40 && count < 42))
		new_x++;
	else
		cout << "Movement path finished or invalid count: " << count << endl;
	x = new_x;
	y = new_y;
	counter++;
	tile_under = board[new_x][new_y];
	board[new_x][new_y] = pawn_no;
	last_x = new_x;
	last_y = new_y;
}
