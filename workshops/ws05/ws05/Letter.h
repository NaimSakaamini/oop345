//
//  Letter.h
//  ws05
//
//  Created by Naim Sakaamini on 2018-10-08.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#ifndef Letter_h
#define Letter_h
#include <string>

namespace sict
{
    enum Letter
    {
        aPlus, A, bPlus, B, cPlus, C, dPlus, D, F
    };
    
    
    template <class T>
    const char* convert(const T& letter)
    {
        const char* grade;
        switch (letter)
        {
            case 0:
                grade = "A+";
                break;
            case 1://or 1:??
                grade = "A";
                break;
            case 2:
                grade = "B+";
                break;
            case 3:
                grade = "B";
                break;
            case 4:
                grade = "C+";
                break;
            case 5:
                grade = "C";
                break;
            case 6:
                grade = "D+";
                break;
            case 7:
                grade = "D";
                break;
            case 8:
                grade = "F";
        }
        return grade;

    }
    
}

#endif /* Letter_h */
