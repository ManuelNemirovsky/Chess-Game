#include "King.h"
King::King(int color, bool kingKiller) : Tool(color, kingKiller)
{
}

King::~King()
{
}

string King::getKind()
{
	return "K";
}
int King::move(string src, string dst, Tool* b[8][8])
{
	int srcInt[] = { src[0] - 'a', src[1] - '1' };
	int dstInt[] = { dst[0] - 'a', dst[1] - '1' };
	if (pow((src[0] - dst[0]), 2) == 1 && pow((src[1] - dst[1]), 2) == 1)//checks if going diagonal
	{
		b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
		b[srcInt[0]][srcInt[1]] = NULL;
		return 0;
	}
	else if (pow((src[0] - dst[0]), 2) == 1 && src[1] - dst[1] == 0)//checks if going right/left
	{
		b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
		b[srcInt[0]][srcInt[1]] = NULL;
		return 0;
	}
	else if (pow((src[1] - dst[1]), 2) == 1 && src[0] - dst[0] == 0)//checks if going up/down
	{
		b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
		b[srcInt[0]][srcInt[1]] = NULL;
		return 0;
	}

	return 6;

}
int King::checkKing(string KingLoc, string src, string dst, Tool* b[8][8])
{
	return false;
}