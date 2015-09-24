
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "board.h"

// Generate the 
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
		std::cout<<"LORD GANGROCK:wrong syntaxe! \n Use : ./life <input_file> [<output_file>]";
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

			if (argc == 3)
			{

				line = argv[2];
				std::ofstream output_file (line);
				if (output_file.is_open())
				{
					std::vector< std::vector<int> > Test;
					int i =0;
					while(test == 'y'){
						Life.print();
						Life.print(output_file);
						Test.push_back(hashingBoard(Life));
						if(Life.getliving()==0){
							std::cout<<"\nLORD GANGROK:BRACE YOURSELF MORTAL APOCALYPSE JUST CAME "<<std::endl;
							break;
						}
						
						std::cout<<"LORD GANGROK: SHALL WE CONTINUE THE EXPERIMENT? (y/n) ";
						for (int j = i -1; j >= 0 ; --j)
						{
							if (Test.at(j) == Test.at(i))
							{
								std::cout<<"\nLORD GANGROK:CONGRATULATIONS MORTAL THE EXPERIMENT IS STABLE"<<std::endl;
								break;
							}
						}

						Life.update();

						std::cin>>test;
						i++;
				}
			
					output_file.close();

				}
				else
					std::cout<<"<output_file> error!";
				

					

			}else{

				std::vector< std::vector<int> > Test;
				int i =0;
				while(test == 'y'){
					Life.print();
					Test.push_back(hashingBoard(Life));
					if(Life.getliving()==0){
						std::cout<<"\nLORD GANGROK:BRACE YOURSELF MORTAL APOCALYPSE JUST CAME "<<std::endl;
						break;
					}
					std::cout<<"LORD GANGROK: SHALL WE CONTINUE THE EXPERIMENT? (y/n) ";
					for (int j = i -1; j >= 0 ; --j)
					{
						if (Test.at(j) == Test.at(i))
						{
							std::cout<<"\nLORD GANGROK:CONGRATULATIONS MORTAL THE EXPERIMENT IS STABLE"<<std::endl;
							break;
						}
					}

					Life.update();

					std::cin>>test;
					i++;
				}

			}
		}
		else
			std::cout<<"LORD GANGROCK:File won't open,puny human";


	
	}
	return 0;
}