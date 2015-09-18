#ifndef _BOARD_
#define _BOARD_

class Board{
	private:
		int nLin;
		int nCol;
		int ** table;
		bool ** tableb;
	public:
		Board(int n, int m);

};

#endif