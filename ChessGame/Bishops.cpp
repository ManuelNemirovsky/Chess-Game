#include "Bishops.h"

Bishops::Bishops(int color, bool kingKiller) : Tool(color, kingKiller)
{

}

Bishops::~Bishops()
{

}

string Bishops::getKind()
{
	return "B";
}

int Bishops::move(string src, string dst, Tool* b[8][8])
{
	int srcInt[] = { src[0] - 'a', src[1] - '1' };
	int dstInt[] = { dst[0] - 'a', dst[1] - '1' };
	int x = 0, y = 0;

	if (abs(srcInt[0] - dstInt[0]) == abs(srcInt[1] - dstInt[1]))
	{
		x = abs(srcInt[0] - dstInt[0]);

		if (srcInt[0] < dstInt[0] && dstInt[1] > srcInt[1])
		{
			for (int i = srcInt[0] + 1, j = srcInt[1] + 1; i < dstInt[0] && j < dstInt[1]; j++, i++)
			{
				if (b[i][j] != NULL)
				{
					return 6;
				}
			}
		}

		if (srcInt[0] > dstInt[0] && dstInt[1] > srcInt[1])
		{
			for (int i = srcInt[0] - 1, j = srcInt[1] + 1; i > dstInt[0] && j < dstInt[1]; j++, i++)
			{
				if (b[i][j] != NULL)
				{
					return 6;
				}
			}
		}

		if (srcInt[0] > dstInt[0] && srcInt[1] > dstInt[1])
		{
			for (int i = srcInt[0] - 1, j = srcInt[1] - 1; i > dstInt[0] && j > dstInt[1]; j--, i--)
			{
				if (b[i][j] != NULL)
				{
					return 6;
				}
			}
		}

		if (srcInt[0] < dstInt[0] && srcInt[1] > dstInt[1])
		{
			for (int i = srcInt[0] + 1, j = srcInt[1] - 1; i < dstInt[0] && j > dstInt[1]; j--, i++)
			{
				if (b[i][j] != NULL)
				{
					return 6;
				}
			}
		}

		b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
		b[srcInt[0]][srcInt[1]] = NULL;

		return 0;
	}
	return 6;
}

int Bishops::checkKing(string KingLoc, string src, string dst, Tool* b[8][8])
{
	int KingLocInt[] = { KingLoc[0] - 'a', KingLoc[1] - '1' };
	int srcInt[] = { src[0] - 'a', src[1] - '1' };
	int dstInt[] = { dst[0] - 'a', dst[1] - '1' };
	int x = 0, y = 0;

	if (abs(dstInt[0] - KingLocInt[0]) == abs(dstInt[1] - KingLocInt[1]))
	{
		x = abs(dstInt[0] - KingLocInt[0]);

		if (dstInt[0] < KingLocInt[0] && KingLocInt[1] > dstInt[1])
		{
			for (int i = dstInt[0] + 1, j = dstInt[1] + 1; i < KingLocInt[0] && j < KingLocInt[1]; j++, i++)
			{
				if (b[i][j] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;

			return 1;
		}

		if (dstInt[0] > KingLocInt[0] && KingLocInt[1] > dstInt[1])
		{
			for (int i = dstInt[0] - 1, j = dstInt[1] + 1; i > KingLocInt[0] && j < KingLocInt[1]; j++, i++)
			{
				if (b[i][j] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;

			return 1;
		}

		if (dstInt[0] > KingLocInt[0] && dstInt[1] > KingLocInt[1])
		{
			for (int i = dstInt[0] - 1, j = dstInt[1] - 1; i > KingLocInt[0] && j > KingLocInt[1]; j--, i--)
			{
				if (b[i][j] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;

			return 1;
		}

		if (dstInt[0] < KingLocInt[0] && dstInt[1] > KingLocInt[1])
		{
			for (int i = dstInt[0] + 1, j = dstInt[1] - 1; i < KingLocInt[0] && j > KingLocInt[1]; j--, i++)
			{
				if (b[i][j] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;

			return 1;
		}
	}
	return 6;
}