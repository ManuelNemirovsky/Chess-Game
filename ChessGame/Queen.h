#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#include "Tool.h"

class Tool;

class Queen : public Tool
{
public:
	Queen(int color, bool kingKiller);
	~Queen();
	string getKind();
	int move(string src, string dst, Tool* b[8][8]);
	int checkKing(string KingLoc, string src, string dst, Tool* b[8][8]);
};
