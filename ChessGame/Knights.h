#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#include "Tool.h"

class Tool;

class Knights : public Tool
{
public:
	Knights(int color, bool kingKiller);
	~Knights();
	string getKind();
	int move(string src, string dst, Tool* b[8][8]);
	int checkKing(string KingLoc, string src, string dst, Tool* b[8][8]);
};
