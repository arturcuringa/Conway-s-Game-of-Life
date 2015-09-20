#include "board.h"



Board::Board(int n, int m): nLin(n), nCol(m){
 
 	state = new bool * [nLin];
 	for (int i = 0; i < nLin; ++i)
 	{
 		state[i] = new bool [nCol];
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
				
				 state[i][j] = true;
			else
				 state[i][j] = false;
		}
	}

}
void Board::print(){
	std::cout<<"\n";
	for (int i = 0; i < nLin; ++i)
	{
		for (int j = 0; j < nCol; ++j)
		{
					std::cout<< (state[i][j] == true ? cell : '-') ;

		}
				std::cout<<'\n';
	}
		
}

void Board::size(){

	std::cout<<nLin<<" "<<nCol<<std::endl;

}

int Board::round(int lin, int col){
	
	if (lin > 0 && lin < nLin -1 && col > 0 && col < nCol -1)
	{
		int i = 0;
		if(state[lin-1][col] == true){++i;}
		if(state[lin-1][col-1] == true){++i;}
		if(state[lin][col-1] == true){++i;}
		if(state[lin+1][col-1] == true){++i;}
		if(state[lin+1][col] == true){++i;}
		if(state[lin+1][col+1] == true){++i;}
		if(state[lin][col+1] == true){++i;}
		return i;
	}

	return 0;

}
void Board::update(){

	for (int i = 0; i < nLin; ++i)
	{
		for (int j = 0; j < nCol; ++j)
		{
			//stub
					
			

		}
			
	}
}


Board::~Board(){
	delete []  state;
}
