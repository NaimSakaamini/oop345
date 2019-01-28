
//  Utilities.cpp
//  milestone1
//
//  Created by Naim Sakaamini on 2018-10-30.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//
#include "Utilities.h"
using namespace std;

char Utilities::delimiter;

Utilities::Utilities(): field_width(1)
{
    
}


void Utilities::setFieldWidth(size_t fw)
{
    field_width = fw;
}


size_t Utilities::getFieldWidth() const
{
    return field_width;
}


const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
    string token;
    more = false;

    if(str.at(next_pos) != getDelimiter())
    {
        token = str.substr(next_pos, str.find(delimiter, next_pos) - next_pos);
        next_pos += token.length()+1;
        
        if (field_width < token.length())
        {
            setFieldWidth(token.length());
        }
        (str.length()+1 != next_pos) ? more = true : more  = false;
    }
    else
    {
        more = false;
        throw("error");
    }
    return token;
}


void Utilities::setDelimiter(const char del)
{
    delimiter = del;
}


const char Utilities::getDelimiter() const
{
    return delimiter;
}
