//
//  Grades.cpp
//  ws05
//
//  Created by Naim Sakaamini on 2018-10-08.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//
#include "Grades.h"
#include <iostream>
#include <fstream>
#include <string>


namespace sict
{
    Grades::Grades(char* file)
    {
         std::ifstream fs;
        try
        {
            fs.open(file);
            if(!fs.is_open())
            {
                throw 0;
            }
        }
        catch (int)
        {
            std::cout << "File not found!" << std::endl;
        }
        std::string line;
       
        while(getline(fs, line))
        {
            size++;
            
        }
        
        fs.close();
        fs.open(file);
        students = new std::string[size];
        grades = new float [size];
        
        int index = 0;
        while (getline(fs, line))
        {
            students[index] = line.substr(0, line.find(' '));
            grades [index] = stof(line.substr(line.find(' '), std::string::npos));
            
            index++;
        }
        
    }
    
    Grades::~Grades()
    {
        delete [] students;
        students = nullptr;
        delete [] grades;
        grades = nullptr;
    }
}
