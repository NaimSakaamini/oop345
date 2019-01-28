//
//  Product.h
//  ws06
//
//  Created by Naim Sakaamini on 2018-10-22.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#ifndef Product_h
#define Product_h
#include "iProduct.h"

namespace w6
{
    class Product : public iProduct
    {
        int ProductNum;
        double Price;
        
    public:
        Product(int, double);
        double getPrice() const;
        void display(std::ostream&) const;
    
    };
}
#endif /* Product_h */
