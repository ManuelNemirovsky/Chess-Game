#include "Pipe.h"
#include "board.h"
#include <string.h>
#include <iostream>
#include <thread>

using namespace std;
void main()
{
	srand(time_t(NULL));

	string src = "";
	string dst = "";
	int answer = 0;

	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	
	board *b = new board("rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0");

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		src = msgFromGraphics[0];
		src += msgFromGraphics[1];

		dst = msgFromGraphics[2];
		dst += msgFromGraphics[3];

		answer = b->move(src, dst);

		msgToGraphics[0] = answer + '0';
		msgToGraphics[1] = 0;


		//strcpy_s(msgToGraphics, &anss); // msgToGraphics should contain the result of the operation

		///******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		///******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}