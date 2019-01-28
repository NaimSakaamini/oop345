// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <fstream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::ofstream ofs("Lab5Output.txt");

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//Update the main functions as per the specifications here
    
    auto letter = [] (float grades)
    {
        Letter grd;
        if ((grades >= 90) && (grades <= 100)) { grd = aPlus; }
        else if ((grades >= 80) && (grades < 90)) { grd = A; }
        else if ((grades >= 75) && (grades < 80)) { grd = bPlus; }
        else if ((grades >= 70) && (grades < 75)) { grd = B; }
        else if ((grades >= 65) && (grades < 70)) { grd = cPlus; }
        else if ((grades >= 60) && (grades < 65)) { grd = C; }
        else if ((grades >= 55) && (grades < 60)) { grd = dPlus; }
        else if ((grades >= 50) && (grades < 55)) { grd = D; }
        else { grd = F; }
        
        return grd;
    };
 
    try
    {
        Grades grades(argv[1]);// dont understand this!!
        grades.displayGrades(ofs, letter);
        
    }
    catch (int x)
    {
        std::cout << " File not Found!" <<std::endl;
    }
	ofs.close();
}
