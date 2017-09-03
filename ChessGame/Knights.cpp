#include "Knights.h"

Knights::Knights(int color, bool kingKiller) : Tool(color, kingKiller)
{

}

Knights::~Knights()
{

}

string Knights::getKind()
{
	return "n";
}

int Knights::move(string src, string dst, Tool* b[8][8])
{
	int srcInt[] = { src[0] - 'a', src[1] - '1' };
	int dstInt[] = { dst[0] - 'a', dst[1] - '1' };
	if ((pow((srcInt[0] - dstInt[0]), 2) + pow((srcInt[1] - dstInt[1]), 2)) == 5)
	{
		b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
		b[srcInt[0]][srcInt[1]] = NULL;
		return 0;
	}
	return 6;

}

int Knights::checkKing(string KingLoc, string src, string dst, Tool* b[8][8])
{
	int KingLocInt[] = { KingLoc[0] - 'a', KingLoc[1] - '1' };
	int srcInt[] = { src[0] - 'a', src[1] - '1' };
	int dstInt[] = { dst[0] - 'a', dst[1] - '1' };
	if ((pow((dstInt[0] - KingLocInt[0]), 2) + pow((dstInt[1] - KingLocInt[1]), 2)) == 2 || (pow((dstInt[0] - KingLocInt[0]), 2) + pow((dstInt[1] - KingLocInt[1]), 2)) == 17)
	{
		b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
		b[srcInt[0]][srcInt[1]] = NULL;
		return 1;
	}
	return 6;
}