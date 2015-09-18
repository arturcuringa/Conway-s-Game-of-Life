#include "board.h"
#include <iostream>


Board::Board(int n, int m): nLin(n), nCol(m){
 
 	celula.state = new bool * [nLin];
 	for (int i = 0; i < nLin; ++i)
 	{
 		celula.state[i] = new bool [nCol];
 	}

 	celula.next = new bool * [nLin];
 	for (int i = 0; i < nLin; ++i)
 	{
 		celula.next[i] = new bool [nCol];
 	}

}


void Board::size(){

	std::cout<<nLin<<" "<<nCol<<std::endl;

}

Board::~Board(){
	delete [] celula.state;
	delete [] celula.next;
}
