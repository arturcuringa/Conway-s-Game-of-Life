#include <iostream>
#include <fstream>
#include <string>

 

int main (int argc, char *argv[] ){
	if(argc != 2){
		std::cout<<"Error: no text input file";
	}
	else{
		std::string line;
		line = argv[1] ;
		std::ifstream myfile(line);
		if (myfile.is_open())
		{
			while(std::getline(myfile,line))
			{

				std::cout<<line<<std::endl;

			}

			myfile.close();
		}
		else
			std::cout<<"File won't open";


	
	}
	

	return 0;
}