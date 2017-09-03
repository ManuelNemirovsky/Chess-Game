#include "Rook.h"

Rook::Rook(int color, bool kingKiller) : Tool(color, kingKiller)
{

}

Rook::~Rook()
{

}

string Rook::getKind()
{
	return "R";
}

int Rook::move(string src, string dst, Tool* b[8][8])
{
	int srcInt[] = { src[0] - 'a', src[1] - '1' };
	int dstInt[] = { dst[0] - 'a', dst[1] - '1' };
	if (srcInt[0] == dstInt[0])
	{
		if (dstInt[1] > srcInt[1])
		{
			for (int i = srcInt[1] + 1; i < dstInt[1]; i++)
			{
				if (b[srcInt[0]][i] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;
		}
		else
		{
			for (int i = srcInt[1]; i < dstInt[1]; i--)
			{
				if (b[srcInt[0]][i] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;
		}

		return 0;
	}

	else if (srcInt[1] == dstInt[1])
	{
		if (dstInt[0] > srcInt[0])
		{
			for (int i = srcInt[0] + 1; i < dstInt[0]; i++)
			{
				if (b[i][srcInt[1]] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;
		}
		else
		{
			for (int i = srcInt[0]; i > dstInt[0]; i--)
			{
				if (b[i][srcInt[1]] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;
		}
		return 0;
	}

	return 6;
}

int Rook::checkKing(string KingLoc, string src, string dst ,Tool* b[8][8])
{
	int srcInt[] = { src[0] - 'a', src[1] - '1' };
	int KingLocInt[] = { KingLoc[0] - 'a', KingLoc[1] - '1' };
	int dstInt[] = { dst[0] - 'a', dst[1] - '1' };

	if (dstInt[0] == KingLocInt[0])
	{
		if (KingLocInt[1] > srcInt[1])
		{
			for (int i = srcInt[1] + 1; i < KingLocInt[1]; i++)
			{
				if (b[srcInt[0]][i] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;
		}
		else
		{
			for (int i = srcInt[1]; i < KingLocInt[1]; i--)
			{
				if (b[srcInt[0]][i] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;
		}

		return 1;
	}

	else if (dstInt[1] == KingLocInt[1])
	{
		if (KingLocInt[0] > srcInt[0])
		{
			for (int i = srcInt[0] + 1; i < KingLocInt[0]; i++)
			{
				if (b[i][srcInt[1]] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;
		}
		else
		{
			for (int i = srcInt[0]; i < KingLocInt[0]; i--)
			{
				if (b[i][srcInt[1]] != NULL)
				{
					return 6;
				}
			}
			b[dstInt[0]][dstInt[1]] = b[srcInt[0]][srcInt[1]];
			b[srcInt[0]][srcInt[1]] = NULL;
		}
		return 1;
	}
	return 6;
}
