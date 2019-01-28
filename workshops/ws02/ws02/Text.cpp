//
//  Text.cpp
//  ws02
//
//  Created by Naim Sakaamini on 2018-09-18.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "Text.h"


namespace w2
{
    //default constructor
    Text::Text()
    {
        strings = nullptr;
        ssize = 0;
    }

    //one parameter constructor
    Text::Text(const std::string& str)
    {
        std::ifstream file("gutenberg_shakespeare.txt");
        if (file.fail())
        {
            *this = Text();
        }
        else
        {
            int counter = 0;
            while(file.eof() == false)
            {
                std::string str;
                getline(file, str);
                counter++;
            }
            ssize = counter;
            strings = new std::string[ssize];
            for (int i = 0; i < ssize; i++)
            {
                getline(file, strings[i]);
            }
            file.close();
            
        }
    }

    //copy construtor
    Text::Text(Text& src)
    {
        ssize = src.ssize;
        strings = new std::string[ssize];
        for (int i = 0; i < ssize; i++)
        {
            strings[i] = src.strings[i];
        }
         
        //*this = src; //doesn't work! why??
        
    }

    //copy operator
    Text& Text::operator=(Text& src)
    {
        if (this != &src)
        {
            ssize = src.ssize;
            delete [] strings;
            strings = new std::string[ssize];
            for (int i = 0; i < ssize; i++)
            {
                strings[i] = src.strings[i];
            }
        }
        return *this;
    }

    //move constructor
    Text::Text(Text&& src)
    {
        //*this = std::move(src); //doesnt work! why??
        

        strings = src.strings;
        ssize = src.ssize;
        src.strings = nullptr;
        
    }

    //move operator
    Text& Text::operator=(Text&& src)
    {
        if (this != &src)
        {
            delete [] strings;
            strings = src.strings;
            ssize = src.ssize;
            src.strings = nullptr;
            
        }
        return *this;
    }

    //destructor
    Text::~Text()
    {
        delete[] strings;
    }

    //size function
    size_t Text::size() const
    {
        return ssize;
    }
}
