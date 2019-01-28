//
//  CustomerOrder.cpp
//  milestone2
//
//  Created by Naim Sakaamini on 2018-11-18.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#include <vector>
#include "Item.h"
#include "CustomerOrder.h"
#include "Utilities.h"


CustomerOrder::CustomerOrder()
{
    Name = '\0';
    Product = '\0';
    ItemCount = 0;
    ItemList = nullptr;
}



CustomerOrder::CustomerOrder(std::string& input) {
    Utilities util;
    bool more;
    size_t currPos = 0;
    ItemCount = 0;
    ItemList = nullptr;
    try {
        Name = util.extractToken(input, currPos, more);
        if (more)
            Product = util.extractToken(input, currPos, more);
        
        size_t tempPos = currPos;
        while(more) {
            std::string dummy = util.extractToken(input, currPos, more);
            ItemCount++;
        }
        
        ItemList = new ItemInfo* [ItemCount];
        currPos = tempPos;
        more = true;
        
        for (size_t i = 0; i < ItemCount; i++){
            std::string dummy = util.extractToken(input, currPos, more);
            if (dummy[dummy.length() - 1] == '\r' || dummy[dummy.length() - 1] == '\n' ){
                dummy = dummy.substr(0, dummy.length() - 1);
            }
            ItemList[i] = new ItemInfo(dummy);
        }
        
        if (field_width < util.getFieldWidth())
            field_width = util.getFieldWidth();
        
    } catch(...){
        std::cout << "error" << std::endl;
    }

}



CustomerOrder::~CustomerOrder()
{
    delete[] ItemList;
}



CustomerOrder::CustomerOrder(CustomerOrder && src)
{
    ItemList = nullptr;
    *this = std::move(src);
}




CustomerOrder & CustomerOrder::operator=(CustomerOrder && src)
{
    if (this != &src)
    {
        Name = src.Name;
        Product = src.Product;
        ItemCount = src.ItemCount;
        field_width = src.field_width;
        ItemList = src.ItemList;
        src.ItemList = nullptr;//thisssssssss was the problem the entire time
    }
    else {
        throw "error";
    }
    return *this;
}




bool CustomerOrder::getOrderFillState()
{
    bool filled = true;
    for (int i = 0; i < ItemCount; i++)
    {
        if (ItemList[i]->FillState == false)
            filled =  false;
    }
    return filled;
}





bool CustomerOrder::getItemFillState(std::string itemName)
{
    bool filled = true;
    for (int i = 0; i < ItemCount; i++)
    {
        if (ItemList[i]->ItemName == itemName)
        {
                filled = ItemList[i]->FillState;
        }
        if (filled == false)
        {
            break;
        }
    }
    return filled;
   
}


void CustomerOrder::fillItem(Item& item, std::ostream& os)
{
    if (item .getQuantity() > 0) {
        for (int i = 0; i < ItemCount; i++) {
            
            // only output the following if item is filled
            if (item.getName().compare(ItemList[i]->ItemName) == 0) {
                item.updateQuantity();
                ItemList[i]->FillState = true;
                os << "Filled " << Name << ", " << Product;
                os << "[" << ItemList[i]->ItemName << "]" << std::endl;
            }
        }
    }
    
}


void CustomerOrder::Display(std::ostream & os)
{
    os << Name << std::endl;
    os << Product << std::endl;
    for (size_t i = 0u; i < ItemCount; i++)
    {
        os << "[" << ItemList[i]->SerialNumber << "]" << ItemList[i]->ItemName << " - "
        << (ItemList[i]->FillState ? "FILLED" : "MISSING") << std::endl;
    }
    
}
