#ifndef _BOARD_
#define _BOARD_

typedef struct{
	bool state,next;
} cel;

class Board{
	private:
		int nLin;
		int nCol;
		int ** table;
		cel ** tableb
	public:
		Board(int n, int m);

};

#endif
