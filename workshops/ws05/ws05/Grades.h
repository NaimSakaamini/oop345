//
//  Grades.h
//  ws05
//
//  Created by Naim Sakaamini on 2018-10-08.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#ifndef Grades_h
#define Grades_h
#include "Letter.h"
#include <iostream>
#include <iomanip>

namespace sict
{
    
    class Grades
    {
        std::string* students;
        float* grades;
        int size = 0;
        
    public:
        Grades(char* file);
        Grades(const Grades& ) = delete;
        Grades& operator=(const Grades& ) = delete;
        Grades(Grades&& ) = delete;
        Grades&& operator=(Grades&& ) = delete;
        ~Grades();
        
        template <typename F>
        void displayGrades(std::ostream& os, F function) const
        {
            
            for (int i = 0; i < size; i++)
            {
                auto letter = function(grades[i]);
                
                os << students[i] <<" "<<  std::setprecision(2)<< std::fixed<<grades[i]<<" "<< convert(letter)<< std::endl;
                
            }
        }
    };
}

#endif /* Grades_h */
