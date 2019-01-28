//
//  iProduct.cpp
//  ws06
//
//  Created by Naim Sakaamini on 2018-10-22.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//
#include "iProduct.h"
#include "Product.h"
#include "TaxableProduct.h"

namespace w6
{

    std::ostream& operator<<(std::ostream& os, const iProduct& prod)
    {
        prod.display(os);
        return os;
    }



    iProduct* readProduct(std::ifstream& in)
    {
        int prodNum;
        double cost;
        char taxes;
        iProduct* prod;
        
        in >> prodNum >> cost;
        taxes = in.get();
        if(taxes == ' ')
        {
            in >> taxes;
        }
        if (taxes == 'H' || taxes == 'P')
        {
           
            prod = new TaxableProduct(prodNum, cost, taxes);
        }
        else
        {
            prod = new Product(prodNum, cost);
        }
        
        
        return prod;
        
    }
}
