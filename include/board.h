#ifndef _BOARD_
#define _BOARD_


#include <iostream>
#include <fstream>
#include <string>


class Board{
	private:
		int nLin;
		int nCol;
		typedef struct{
			bool ** state;
			bool ** next;
		} cel;
		cel celula;
		char cell;
	public:
		Board(int n, int m);
		void size();
		void setAlive(std::ifstream &text);
		~Board();
		void print();
		int round(int lin, int col);
		void update();
			 
};

#endif
