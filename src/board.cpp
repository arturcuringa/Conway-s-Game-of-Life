#include "board.h"



Board::Board(int n, int m): nLin(n), nCol(m){
 
 	state = new bool * [nLin];
 	for (int i = 0; i < nLin; ++i)
 	{
 		state[i] = new bool [nCol];
 	}
	
}

bool Board::operator==(const Board& b )const{

	if (nLin != b.nLin || nCol != b.nCol || living != b.living || dead != b.dead )
	{
		return false;
	}


	for (int i = 0; i < nLin; ++i)
	{
		for (int j = 0; j < nCol; ++j)
		{
			if(state[i][j] != b.state[i][j] )
				return false;
		}
	}

	return true;
}
Board& Board::operator=(const Board & b ){

	living = b.living;
	dead = b.dead;
	nLin = b.nLin;
	nCol = b.nCol;
	delete [] state;

	state = new bool * [nLin];
 	for (int i = 0; i < nLin; ++i)
 	{
 		state[i] = new bool [nCol];
 	}

 	for (int i = 0; i < nLin; ++i)
 	{
 		for (int j = 0; j < nCol; ++j)
 		{
 			state[i][j] = b.state[i][j];
 		}
 	}
 	return *this;

}

void Board::setAlive(std::ifstream &text){
	std::string line;


	std::getline(text,line);
	cell = line[0];
	for (int i = 0; i < nLin; ++i)
	{
		std::getline(text, line);
		for (int j = 0; j < nCol; ++j)
		{
			if(line[j] == cell)
			{
				living++;
				state[i][j] = true;
			}	
			else{
				dead++;
				state[i][j] = false;
			}
		}
	}

}
void Board::print(){
	std::cout<<"Showing generation: "<< ++generation <<":"<<std::endl;
	for (int i = 0; i < nLin; ++i)
	{
		std::cout<<"[";
		for (int j = 0; j < nCol; ++j)
		{
			std::cout<< (state[i][j] == true ? '*' : ' ') ;

		}
		std::cout<<"]\n";
	}
}

void Board::size(){

	std::cout<<nLin<<" "<<nCol<<std::endl;

}

int Board::round(int lin, int col){
	
	int i = 0;
		if(lin-1>=0 && state[lin-1][col] == true  ){++i;}
		if(lin-1>=0 && col-1>=0 && state[lin-1][col-1] == true ){++i;}
		if(col-1>=0 && state[lin][col-1] == true  ){++i;}
		if(lin+1<nLin &&col-1>=0 && state[lin+1][col-1] == true ){++i;}
		if(lin+1<nLin && state[lin+1][col] == true ){++i;}
		if(lin+1<nLin && col+1<nCol && state[lin+1][col+1] == true   ){++i;}
		if(col+1<nCol && state[lin][col+1] == true ){++i;}
		if(lin-1>=0 &&col+1<nCol && state[lin-1][col+1] == true ){++i;}
		
	return i;

}
void Board::update(){

	bool ** next = new bool * [nLin];
 	for (int i = 0; i < nLin; ++i)
 	{
 		next[i] = new bool [nCol];
 	}

 	int around = round(i,j);

	for (int i = 0; i < nLin; ++i)
	{
		for (int j = 0; j < nCol; ++j)
		{
			
			if (state[i][j] == true )
			{
				if (around <= 1 || around >=4)
				{
					--living;
					++dead;
					next[i][j] = false;
				}
				else if (around == 2 || around == 3)
				{
					next[i][j] = true;
				}
				
			}
			else if (state[i][j] == false)
			{
				if (around == 3)
				{
					dead--;
					++living;
					next[i][j] = true;
				}
				else{
					next[i][j] = false;			
				}
			}
			
				

		}
			
	}

	delete [] state;
	state = next;


}


Board::~Board(){
	delete []  state;
}
