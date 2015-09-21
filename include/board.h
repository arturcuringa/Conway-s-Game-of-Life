#ifndef _BOARD_
#define _BOARD_


#include <iostream>
#include <fstream>
#include <string>


class Board{
	private:
		int nLin; // Number of lines of the board
		int nCol; // Number of collums 
		bool ** state; // Pointer to boolean array of arrays 
		char cell; //Type of char used to represent a living cell
		long long unsigned int living = 0;
	public:
		Board(int n, int m); // Constructor 
		void size(); // Print size of the board
		void setAlive(std::ifstream &text); // Set Board with text file
		~Board(); // Destructor 
		void print(); // Print the actual state of the board
		int round(int lin, int col);// Count how many living cells are surrounding the space lin x col
		void update(); // Update the board with the rules of ~~~~Life's game
			 
};

#endif
