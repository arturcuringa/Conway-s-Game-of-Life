#include "board.h"


/** \brief Constructor */
Board::Board(int n, int m): nLin(n), nCol(m){
 	
 	/**
		\details Create a dynamic allocated matrix of boolean to represent the board an initialize the class
		\param Integer values of lines and columns 
		\return Create a new object of Board class
 	 */
 	state = new bool * [nLin];
 	for (int i = 0; i < nLin; ++i)
 	{
 		state[i] = new bool [nCol];
 	}
	
}
/** \brief operator == Overloading*/
bool Board::operator==(const Board& b )const{

	/**
		\details Overloads the operator == of Board class, so it can be used to verify if one Board is equal to another Board
		\param The other Board (b) by reference
		\return Bool if this Board is equal to b Board 

	 */

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
/** \brief operator = Overloading  */
Board& Board::operator=(const Board & b ){
	/**
		\deatails Overloads the operator = of the Board class, so it can be used to Board attribution
		\param The Board b that will be the value of this Board
		\return The reference of this Board
	 */
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


/** \brief setAlive */
void Board::setAlive(std::ifstream &text){
	std::string line;

	/**
		\details Set Values to the this Board, Make it live !
		\param Stream of input text file 
		\return Void
	 */
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

/**  \brief print on Terminal */
void Board::print(){
	/** 
		\details Print the Board in the terminal 
		\param void
		\return void
	
	*/
	std::cout<<"Showing generation: "<< generation <<":"<<std::endl;
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
void Board::print(std::ofstream &text){
	text << "Showing generation: "<< generation <<":"<<std::endl;

	for (int i = 0; i < nLin; ++i)
	{
		std::string line;
		text <<"[";
		for (int j = 0; j < nCol; ++j)
		{
			line += (state[i][j] == true ? '*' : ' ') ;

		}
		text << line;
		text<<"]\n";
	}

}
/** \brief Size, print size */
void Board::size(){
	/** 
		\details Print the size of the board on screen
		\param void
		\return void
	*/
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
	++generation;
	bool ** next = new bool * [nLin];
 	for (int i = 0; i < nLin; ++i)
 	{
 		next[i] = new bool [nCol];
 	}

 	

	for (int i = 0; i < nLin; ++i)
	{
		
		for (int j = 0; j < nCol; ++j)
		{
			int around = round(i,j);
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
