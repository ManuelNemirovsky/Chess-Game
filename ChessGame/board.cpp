#include "Board.h"
#include <string>

using namespace std;

Tool* board:: operator()(int x, int y)
{
	return this->_chessBoard[x][y];
}

board::board(string boardPlayers)
{
	int i = 0;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			switch (boardPlayers[i])
			{
			case 'r':
				_chessBoard[col][row] = new Rook(1, false);
				break;
			case 'n':
				_chessBoard[col][row] = new Knights(1, false);
				break;
			case 'b':
				_chessBoard[col][row] = new Bishops(1, false);
				break;
			case 'k':
				_chessBoard[col][row] = new King(1, false);
				_enemyKing[0] = col;
				_enemyKing[1] = row;
				break;
			case 'q':
				_chessBoard[col][row] = new Queen(1, false);
				break;
			case 'p':
				_chessBoard[col][row] = new Powns(1, false);
				break;

			case 'R':
				_chessBoard[col][row] = new Rook(0, false);
				break;
			case 'N':
				_chessBoard[col][row] = new Knights(0, false);
				break;
			case 'B':
				_chessBoard[col][row] = new Bishops(0, false);
				break;
			case 'K':
				_chessBoard[col][row] = new King(0, false);
				_currentKing[0] = col;
				_currentKing[1] = row;
				break;
			case 'Q':
				_chessBoard[col][row] = new Queen(0, false);
				break;
			case 'P':
				_chessBoard[col][row] = new Powns(0, false);
				break;
			default:
				_chessBoard[col][row] = NULL;
				break;
			}
			i++;
		}
	}

	print();
}

void board::print()
{
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			if (_chessBoard[row][column] != NULL)
				cout << _chessBoard[row][column]->getKind();
			else
				cout << '#';
		}
		cout << "\n";
	}
}

board::~board()
{
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			delete _chessBoard[row][column];
		}
	}
}

int board::move(string src , string dst)
{
	int source[] = { src[0] - 'a', src[1] - '1'};
	int dest[] = { dst[0] - 'a', dst[1] - '1' };
	string firstCurrentKing = "";
	string secCurrentKing = "";
	string firstEnemyKing = "";
	string secEnemyKing = "";
	char a = '0';
	int ans = 0;
	bool Shah = false;

	a = _currentKing[0] + 'a';

	firstEnemyKing += a;
	firstEnemyKing += to_string(_currentKing[1]);

	a = _enemyKing[0] + 'a';

	firstCurrentKing += a;
	firstCurrentKing += to_string(_enemyKing[1]);

	
	if (src.compare(dst) == 0)
	{
		return 7;
	}

	if (src.compare(firstCurrentKing) == 0)
	{
		return 6;
	}

	if (_chessBoard[source[0]][source[1]] == NULL)
	{
		return 2;
	}

	if (_chessBoard[dest[0]][dest[1]] != NULL)
	{
		if (_chessBoard[source[0]][source[1]]->getColor() == _chessBoard[dest[0]][dest[1]]->getColor())
		{
			return 3;
		}
	}

	if (src[0] > 'h' || src[0] < 'a' && src[1] > '8' || src[1] < '1' && dst[0] > 'h' || dst[0] < 'a' && dst[1] > '8' || dst[1] < '1')
	{
		return 5;
	}

	/*if (_chessBoard[source[0]][source[1]]->checkKing(firstCurrentKing, dst, _chessBoard) == 1)
	{
		return 4;
	}*/

	if (_chessBoard[source[0]][source[1]]->checkKing(firstEnemyKing, src , dst, _chessBoard) == 1)
	{
		return 1;
	}

	ans = _chessBoard[source[0]][source[1]]->move(src, dst, _chessBoard);

	print();

	return ans;
}
