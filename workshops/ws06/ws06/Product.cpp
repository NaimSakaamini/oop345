//
//  Product.cpp
//  ws06
//
//  Created by Naim Sakaamini on 2018-10-22.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//


#include "Product.h"
#include <iostream>

namespace w6
{
    Product::Product(int num, double price)
    {
        this->ProductNum = num;
        this->Price = price;
    }
    
    double Product:: getPrice() const
    {
        return Price;
    }

    
    
    void Product:: display(std::ostream& os) const
    {
        os << ProductNum << " " << Price;
        
    }
}
