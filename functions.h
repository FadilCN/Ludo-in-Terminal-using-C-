#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include "classes.h"
using namespace std;

int rollDice();
int incrPlayerId(int id);
void draw(string (&board)[15][15]);
void print(string (&board)[15][15]);
void waitForEnter();
void turns(int color, int pawn_no, string (&board)[15][15]);
void fill(int playerId,int* current_player[4], int index, string (&board)[15][15]);
void checkWinCondition(int playerId, int* current_player[4], int win[4], int pawn);
void releasePawn(int playerId, int &available, string (&board)[15][15], int* current_player[4]);
void movePawn(int playerId, int pawnIndex, int num, string (&board)[15][15], int* current_player[4]);
void handleSixRoll(int playerId, int &available, int num, string (&board)[15][15], int* current_player[4]);


extern int win[4];
extern const int MAX_STEPS;

#endif
