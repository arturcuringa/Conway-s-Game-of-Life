#include "board.h"



Board::Board(int n, int m): x(n), y(m){
 	table = new int* [x];
 	for (int i = 0; i < x; ++i)
 	{
 		table[x] = new int [y];
 	}

 	tableb = new bool* [x];
 	for (bool i = 0; i < x; ++i)
 	{
 		tableb[x] = new bool [y];
 	}


};