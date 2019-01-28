//
//  TaxableProduct.h
//  ws06
//
//  Created by Naim Sakaamini on 2018-10-22.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#ifndef TaxableProduct_h
#define TaxableProduct_h
#include "Product.h"

namespace w6
{
const double HST = 1.13;
const double PST = 1.08;
    
    class TaxableProduct : public Product
    {
        char taxes;
        double taxesArray[2] = {HST , PST};
        
    public:
        TaxableProduct(int, double, char);
        double getPrice() const;
        void display(std::ostream&) const;
    };
}
#endif /* TaxableProduct_h */
