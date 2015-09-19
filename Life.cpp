#include <iostream>
#include <fstream>
#include <string>
#include "board.h"
 

int main (int argc, char *argv[] ){
	int nLin;
	int nCol;

	if(argc != 2){
		std::cout<<"Error: no text input file";
	}
	else{
		std::string line;
		line = argv[1] ;
		std::ifstream myfile(line);
		if (myfile.is_open())
		{
			std::getline(myfile,line);
			std::string::size_type sz;
			nLin = std::stoi(line, &sz);
			nCol = std::stoi(line, &sz);
			
			Board Life(nLin, nCol);
			Life.size();
			Life.setAlive(myfile);
			Life.print();
			myfile.close();
		}
		else
			std::cout<<"File won't open";


	
	}
	

	return 0;
}