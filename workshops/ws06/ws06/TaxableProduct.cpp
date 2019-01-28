//
//  TaxableProduct.cpp
//  ws06
//
//  Created by Naim Sakaamini on 2018-10-22.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#include "TaxableProduct.h"

namespace w6
{
    TaxableProduct::TaxableProduct(int num, double price, char taxes) : Product(num, price)
    {
        this->taxes = taxes;
    }
    
    
    double TaxableProduct:: getPrice() const
    {
        double price;
        price = (taxes == 'H') ? price = Product::getPrice() * taxesArray[0] : price = Product::getPrice() * taxesArray[1];
        return price;
    }
    
    void TaxableProduct::display(std::ostream& os) const
    {
        Product::display(os);
        if (this->taxes == 'H')
            os << " HST";
        else if(this->taxes == 'P')
            os << " PST";
    }
}
