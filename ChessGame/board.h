#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#include "Tool.h"
#include "Rook.h"
#include "King.h"
#include "Bishops.h"
#include "Knights.h"
#include "Queen.h"
#include "Powns.h"

class Tool;
class Rook;
class King;
class Bishops;
class Knights;
class Queen;
class Powns;

class board
{

public:
	board(string boardPlayers);
	~board();
	void print();
	int move(string src, string dst);
	Tool* getBoard();
	Tool* operator()(int x, int y);

private:
	Tool* _chessBoard[8][8];
	int _currentKing[2];
	int _enemyKing[2];
};