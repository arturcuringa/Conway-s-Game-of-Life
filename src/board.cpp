#include "board.h"



Board::Board(int n, int m): nLin(n), nCol(m){
 
 	tableb.state = new bool* [nLin];
 	for (bool i = 0; i < nLin; ++i)
 	{
 		tableb[nLin] = new bool [nCol];
 	}


};
