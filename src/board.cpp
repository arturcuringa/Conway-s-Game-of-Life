#include "board.h"



Board::Board(int n, int m): nLin(n), nCol(m){
 	table = new int* [nLin];
 	for (int i = 0; i < nLin; ++i)
 	{
 		table[nLin] = new int [nCol];
 	}

 	tableb = new bool* [nLin];
 	for (bool i = 0; i < nLin; ++i)
 	{
 		tableb[nLin] = new bool [nCol];
 	}


};