#ifndef _BOARD_
#define _BOARD_

class Board{
	private:
		int x;
		int y;
		int ** table;
		bool ** tableb;
	public:
		Board(int n, int m);

};

#endif