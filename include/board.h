#ifndef _BOARD_
#define _BOARD_



class Board{
	private:
		int nLin;
		int nCol;
		typedef struct{
			bool ** state;
			bool ** next;
		} cel;
		cel celula;
	public:
		Board(int n, int m);
		void size();
		~Board();

};

#endif
