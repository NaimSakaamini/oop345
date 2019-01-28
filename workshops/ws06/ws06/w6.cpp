 // Workshop 6 - STL Containers
 // w6.cpp

 #include <iostream>
 #include <fstream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include "iProduct.h"

 int main(int argc, char** argv) {

	 std::ofstream ofs("Lab6Output.txt");

     std::cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         std::cout << argv[i] << ' ';
     }
     std::cout << std::endl;
     if (argc != 2) {
         std::cerr << "\n***Incorrect number of arguments***\n";
         return 1;
     }
     std::ifstream productList(argv[1]);
     if (!productList) {
         std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
         return 2;
     }
     ofs << std::fixed << std::setprecision(2);

	//Add your code here
     try {
         std::vector<w6::iProduct*> vec;
         while (productList)
         {
             vec.push_back(w6::readProduct(productList));
         }
         
         double total = 0;
         ofs << "Product No      Price  Taxable \n";
         
         for (int i = 0; i <vec.size(); i++)
         {
             ofs << *vec[i];
             total += vec[i]->getPrice();
             ofs << '\n';
         }
         
         ofs << "Total:   " << total <<std::endl;
     }
     catch (const char* str)
     {
         ofs << str;
         return 2;
     }
     
     
     

     std::cout << "Results are in Lab6Output.txt\nPress any key to continue ... ";
     std::cin.get();

	 ofs.close();
 }

