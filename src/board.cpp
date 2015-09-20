#include "board.h"



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
void Board::setAlive(std::ifstream &text){
	std::string line;


	std::getline(text,line);
	cell = line[0];
	std::cout<<cell;
	for (int i = 0; i < nLin; ++i)
	{
		std::getline(text, line);
		for (int j = 0; j < nCol; ++j)
		{
			if(line[j] == cell)
				
				celula.state[i][j] = true;
			else
				celula.state[i][j] = false;
		}
	}

}
void Board::print(){
	std::cout<<"\n";
	for (int i = 0; i < nLin; ++i)
	{
		for (int j = 0; j < nCol; ++j)
		{
					std::cout<< (celula.state[i][j] == true ? cell : '-') ;

		}
				std::cout<<'\n';
	}
		
}

void Board::size(){

	std::cout<<nLin<<" "<<nCol<<std::endl;

}

Board::~Board(){
	delete [] celula.state;
	delete [] celula.next;
}
