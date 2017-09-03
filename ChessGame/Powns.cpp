#include "Powns.h"

Powns::Powns(int color, bool kingKiller) : Tool(color, kingKiller)
{

}

Powns::~Powns()
{

}

string Powns::getKind()
{
	return "P";
}

int Powns::move(string src, string dst, Tool* b[8][8])
{
	int srcInt[] = { src[0] - 'a', src[1] - '1' };
	int dstInt[] = { dst[0] - 'a', dst[1] - '1' };
	int i = 0;
	if (srcInt[1] == 6 || srcInt[1] == 1)
	{
		if (pow(srcInt[1] - dstInt[1], 2) == 4)
		{
			if (srcInt[0] > dstInt[0])
			{
				if (b[srcInt[0]][srcInt[1] - 1] != NULL)
				{
					return 6;
				}
			}
			else if (srcInt[0] < dstInt[0])
			{
				if (b[srcInt[0]][srcInt[1] + 1] != NULL)
				{
					return 6;
				}

			}
		}

		if (((srcInt[0] == dstInt[0]) && ((abs(srcInt[1] - dstInt[1]) == 2) || abs(srcInt[1] - dstInt[1]) == 1)) && b[dstInt[0]][dstInt[1]] == NULL)
		{
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;
			return 0;
		}
	}
	else
	{
		if (((srcInt[0] == dstInt[0]) && (pow(srcInt[1] - dstInt[1], 2) == 1)) && b[dstInt[0]][dstInt[1]] == NULL)
		{
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;
			return 0;
		}
	}
	if ((pow((srcInt[0] - dstInt[0]), 2) == 1 && pow((srcInt[1] - dstInt[1]), 2) == 1) && b[dstInt[0]][dstInt[1]] != NULL)
	{
		b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
		b[srcInt[0]][srcInt[1]] = NULL;
		return 0;
	}
	return 6;

}

int Powns::checkKing(string KingLoc, string src, string dst, Tool* b[8][8])
{
	int srcInt[] = { src[0] - 'a', src[1] - '1' };
	int dstInt[] = { dst[0] - 'a', dst[1] - '1' };
	int KingLocInt[] = { KingLoc[0] - 'a', KingLoc[1] - '1' };

	if (abs(srcInt[0] - dstInt[0]) == abs(srcInt[1] - dstInt[1]) && b[dstInt[0]][dstInt[1]] != NULL)
	{
		for (int i = dstInt[0] + 1, j = dstInt[1] + 1; i < KingLocInt[0] && j < KingLocInt[1]; j++, i++)
		{
			if (b[i][j] != NULL)
			{
				return 0;
			}
		}

		for (int i = dstInt[0] + 1, j = dstInt[1] - 1; i < KingLocInt[0] && j > KingLocInt[1]; j--, i++)
		{
			if (b[i][j] != NULL)
			{
				return 0;
			}
		}
		b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
		b[srcInt[0]][srcInt[1]] = NULL;
		return 1;
	}
	return 0;
}