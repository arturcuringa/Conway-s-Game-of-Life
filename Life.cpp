#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "board.h"


std::vector<int> hashingBoard( Board&  b){

	std::vector<int> result;
	int k= 0;
	int col = b.getnCol();
	int lin = b.getnLin();
	for (int i = 0; i < col ; ++i)
	{
		for (int j = 0; j < lin ; ++j)
		{
			k++;
			if (b.getcell(i,j) == true)
			{
				result.push_back(k);
			}
		}
	}
	return result;
}
 



int main (int argc, char *argv[] ){
	int nLin;
	int nCol;
	char test = 'y';

	if(argc < 2){
		std::cout<<"Wrong syntaxe! \n Use : ./life <input_file> [<output_file>]";
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
			Life.setAlive(myfile);
			myfile.close();

			std::vector< std::vector<int> > Test;
			int i =0;
			while(test == 'y'){
				Life.print();
				Test.push_back(hashingBoard(Life));
				std::cout<<"Continue viewing next generation? (y/n) ";
				for (int j = i -1; j >= 0 ; --j)
				{
					if (Test.at(j) == Test.at(i))
					{
						std::cout<<"Stable!!"<<std::endl;
					}
				}

				Life.update();

				std::cin>>test;
				i++;
			}


		}
		else
			std::cout<<"File won't open";


	
	}
	

	return 0;
}