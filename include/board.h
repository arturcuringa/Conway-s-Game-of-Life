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
		int dead = 0; // Dead cells count
		int living = 0; // living cells count
		int generation = 0;
	public:
		Board(int n, int m); // Constructor
		int getnLin(){return nLin;}; // Return the number of lines
		int getnCol(){return nCol;}; // Return de number of columns
		bool getcell(int x, int y){return state[x][y]; }; //Return the state of a cell "No exception yet"
		int getliving(){return living;}; // Return living cells
		int getdead(){return dead;}; // Return dead cells
		bool operator==(const Board & b )const; //Board comparassion operator overload
		Board& operator=(const Board & b ); // Board atribution operator overload
		void size(); // Print size of the board
		void setAlive(std::ifstream &text); // Set Board with text file
		~Board(); // Destructor 
		void print(); // Print the actual state of the board on terminal
		void print(std::ofstream &text);
		int round(int lin, int col);// Count how many living cells are surrounding the space lin x col
		void update(); // Update the board with the rules of ~~~~Life's game
			 
};

#endif
