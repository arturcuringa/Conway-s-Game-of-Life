#include <iostream>
#include <fstream>
#include <string>
#include "board.h"
 

int main (int argc, char *argv[] ){
	int nLin;
	int nCol;
	char test = 'y';

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
			myfile.close();
			
			while(test == 'y'){
			Life.print();
			std::cout<<"Wanna try, bro? (y/n)"<<std::endl;
			Life.update();
			//std::cout<<Life.round(3,3);
			std::cin>>test;
			}


		}
		else
			std::cout<<"File won't open";


	
	}
	

	return 0;
}