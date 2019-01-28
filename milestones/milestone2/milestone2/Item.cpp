
//  Item.cpp
//  milestone1
//
//  Created by Naim Sakaamini on 2018-10-30.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#include "Item.h"
#include "Utilities.h"
using namespace std;

unsigned int Item::field_width;

Item::Item(std::string& record) {
    Utilities util;
    size_t pos = 0;
    bool more = true;
    
    
    try
    {
        name = util.extractToken(record, pos, more);
        if (more)
        {
            serialNumber = (unsigned int)stoul(util.extractToken(record, pos, more));
        }
        if (more)
        {
            Quantity = stoi(util.extractToken(record, pos, more));
        }
        if (more)
        {
            description = util.extractToken(record, pos, more);
        }
        if (field_width < util.getFieldWidth())
        {
            field_width = (unsigned int)util.getFieldWidth();
        }
    }
    catch(string err)
    {
        cout << err << endl;
    }
    
    
}


const std::string& Item::getName() const
{
    return name;
}


const unsigned int Item::getSerialNumber()
{
    return serialNumber++;
}


const unsigned int Item::getQuantity()
{
    return Quantity;
}


void Item::updateQuantity()
{
    if(Quantity > 0)
    {
        Quantity--;
    }
}

void Item::display(std::ostream& os, bool full) const {
    os << std::left << std::setw(field_width) << name;
    os << "[" << std::right << serialNumber << "]";
    if (full) {
        os << std::left << " Quantity " << Quantity;
        os << " Description: " << description << std::endl;
    }
    else {
        os << std::endl;
    }
}
