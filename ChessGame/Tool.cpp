#include "Tool.h"

Tool::Tool(int color, bool kingKiller)
{
	_color = color;
	_kingKiller = kingKiller;
}

Tool::Tool(Tool *copy)
{
	_color = copy->getColor();
	_kingKiller = copy->getKingKiller();
}

Tool::~Tool()
{

}

int Tool::getColor()
{
	return _color;
}

bool Tool::getKingKiller()
{
	return _kingKiller;
}
