#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Tool
{
public:
	Tool(int color, bool kingKiller);
	Tool(Tool *copy);
	~Tool();

	virtual int move(string src, string dst, Tool* b[8][8]) = 0;
	int getColor();
	bool getKingKiller();
	virtual int checkKing(string KingLoc, string src, string dst, Tool* b[8][8]) = 0;
	virtual string getKind() = 0;

private:
	int _color;
	bool _kingKiller;
};
