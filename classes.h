#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <string>
using namespace std;

#define RED     "\033[41m"
#define YELLOW  "\033[43m"
#define BLUE    "\033[44m"
#define GREEN   "\033[42m"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"

class PawnR {
public:
	int x, y, last_x, last_y, counter;
	string tile_under;
	PawnR(int startX, int startY);
	void move(string (&board)[15][15], string pawn_no);
};

class PawnG {
public:
	int x, y, last_x, last_y, counter;
	string tile_under;
	PawnG(int startX, int startY);
	void move(string (&board)[15][15], string pawn_no);
};

class PawnB {
public:
	int x, y, last_x, last_y, counter;
	string tile_under;
	PawnB(int startX, int startY);
	void move(string (&board)[15][15], string pawn_no);
};

class PawnY {
public:
	int x, y, last_x, last_y, counter;
	string tile_under;
	PawnY(int startX, int startY);
	void move(string (&board)[15][15], string pawn_no);
};

#endif
